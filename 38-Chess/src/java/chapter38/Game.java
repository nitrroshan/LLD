package chapter38;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * Coordinator — owns the board, turn order, status (State), observers, and the
 * move history (Command stack). Validates and applies moves, detects
 * check/checkmate/stalemate, and supports undo.
 */
public class Game {
    private final Board board = new Board();
    private final List<GameObserver> observers = new ArrayList<>();
    private final Deque<MoveCommand> history = new ArrayDeque<>();
    private Color currentTurn = Color.WHITE;
    private GameState state = ActiveState.instance();

    public Game() {
        setupStandardBoard();
    }

    public void addObserver(GameObserver observer) {
        observers.add(observer);
    }

    /**
     * Attempts a move. Returns true if it was legal and applied.
     */
    public boolean makeMove(Position from, Position to) {
        if (state.isGameOver()) {
            System.out.println("  Game is over (" + state.name() + ")");
            return false;
        }
        Piece piece = board.getPiece(from);
        if (piece == null || piece.color() != currentTurn) {
            System.out.println("  No " + currentTurn + " piece at " + from);
            return false;
        }
        Piece target = board.getPiece(to);
        if (target != null && target.color() == currentTurn) {
            System.out.println("  Cannot capture your own piece");
            return false;
        }
        if (!piece.canMove(board, from, to)) {
            System.out.println("  Illegal move for " + piece + ": " + from + "->" + to);
            return false;
        }

        // Simulate to ensure the move doesn't leave our own king in check.
        MoveCommand command = new MoveCommand(board, from, to);
        command.execute();
        if (board.isSquareAttacked(board.findKing(currentTurn), currentTurn.opposite())) {
            command.undo();
            System.out.println("  Illegal: move would leave your king in check");
            return false;
        }

        // Legal — commit.
        history.push(command);
        for (GameObserver o : observers) {
            o.onMove(from, to, board.getPiece(to), command.captured());
        }

        currentTurn = currentTurn.opposite();
        updateStatusForSideToMove();
        return true;
    }

    /** Undoes the last move (restores captured piece and turn). */
    public void undo() {
        if (history.isEmpty()) {
            System.out.println("  Nothing to undo");
            return;
        }
        MoveCommand last = history.pop();
        last.undo();
        currentTurn = currentTurn.opposite();
        state = ActiveState.instance();
        System.out.println("  Undid " + last.to() + "->" + last.from());
    }

    private void updateStatusForSideToMove() {
        boolean inCheck = board.isSquareAttacked(board.findKing(currentTurn), currentTurn.opposite());
        boolean hasMove = hasAnyLegalMove(currentTurn);

        if (inCheck && !hasMove) {
            state = CheckmateState.instance();
            for (GameObserver o : observers) o.onCheckmate(currentTurn.opposite());
        } else if (!inCheck && !hasMove) {
            state = StalemateState.instance();
            for (GameObserver o : observers) o.onStalemate();
        } else if (inCheck) {
            state = CheckState.instance();
            for (GameObserver o : observers) o.onCheck(currentTurn);
        } else {
            state = ActiveState.instance();
        }
    }

    /** Tries every pseudo-legal move; keeps those that leave the king safe. */
    private boolean hasAnyLegalMove(Color color) {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                Piece piece = board.getPiece(new Position(r, c));
                if (piece == null || piece.color() != color) continue;
                Position from = new Position(r, c);
                for (int tr = 0; tr < 8; tr++) {
                    for (int tc = 0; tc < 8; tc++) {
                        Position to = new Position(tr, tc);
                        Piece target = board.getPiece(to);
                        if (target != null && target.color() == color) continue;
                        if (!piece.canMove(board, from, to)) continue;
                        MoveCommand trial = new MoveCommand(board, from, to);
                        trial.execute();
                        boolean safe = !board.isSquareAttacked(board.findKing(color), color.opposite());
                        trial.undo();
                        if (safe) return true;
                    }
                }
            }
        }
        return false;
    }

    public Board board() { return board; }
    public GameState state() { return state; }
    public Color currentTurn() { return currentTurn; }

    private void setupStandardBoard() {
        // Pawns.
        for (int c = 0; c < 8; c++) {
            board.setPiece(new Position(1, c), PieceFactory.create(Color.WHITE, PieceType.PAWN));
            board.setPiece(new Position(6, c), PieceFactory.create(Color.BLACK, PieceType.PAWN));
        }
        // Back ranks.
        PieceType[] order = {
            PieceType.ROOK, PieceType.KNIGHT, PieceType.BISHOP, PieceType.QUEEN,
            PieceType.KING, PieceType.BISHOP, PieceType.KNIGHT, PieceType.ROOK
        };
        for (int c = 0; c < 8; c++) {
            board.setPiece(new Position(0, c), PieceFactory.create(Color.WHITE, order[c]));
            board.setPiece(new Position(7, c), PieceFactory.create(Color.BLACK, order[c]));
        }
    }
}
