package chapter31;

import java.util.List;

/**
 * Concrete Strategy — a simple heuristic AI:
 *   1) win now if possible, 2) block an opponent win, 3) take center,
 *   4) take a corner, 5) otherwise the first available cell.
 * Look-ahead is done on board copies, so it has no side effects.
 */
public class RuleBasedAiStrategy implements MoveStrategy {
    @Override
    public Move chooseMove(Board board, Symbol symbol) {
        Symbol opponent = (symbol == Symbol.X) ? Symbol.O : Symbol.X;
        List<Move> moves = board.availableMoves();

        // 1) Winning move
        for (Move move : moves) {
            Board copy = board.copy();
            copy.placeMark(move, symbol);
            if (copy.getWinner() == symbol) {
                return move;
            }
        }
        // 2) Block opponent's winning move
        for (Move move : moves) {
            Board copy = board.copy();
            copy.placeMark(move, opponent);
            if (copy.getWinner() == opponent) {
                return move;
            }
        }
        // 3) Center
        int mid = board.getSize() / 2;
        Move center = new Move(mid, mid);
        if (board.isValid(center)) {
            return center;
        }
        // 4) Corners
        int last = board.getSize() - 1;
        Move[] corners = {
            new Move(0, 0), new Move(0, last), new Move(last, 0), new Move(last, last)
        };
        for (Move corner : corners) {
            if (board.isValid(corner)) {
                return corner;
            }
        }
        // 5) First available
        return moves.get(0);
    }
}
