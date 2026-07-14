package chapter38;

/**
 * Command — a single move. execute() applies it and remembers the captured
 * piece and the moved piece's prior "hasMoved" flag; undo() restores both,
 * which is what makes king-safety simulation and undo/redo possible.
 */
public class MoveCommand implements Command {
    private final Board board;
    private final Position from;
    private final Position to;
    private Piece moved;
    private Piece captured;
    private boolean previousHasMoved;

    public MoveCommand(Board board, Position from, Position to) {
        this.board = board;
        this.from = from;
        this.to = to;
    }

    @Override
    public void execute() {
        moved = board.getPiece(from);
        previousHasMoved = moved.hasMoved();
        captured = board.movePiece(from, to);
        moved.setMoved(true);
    }

    @Override
    public void undo() {
        board.movePiece(to, from);       // move the piece back
        board.setPiece(to, captured);    // restore whatever was captured (or null)
        moved.setMoved(previousHasMoved);
    }

    public Position from() { return from; }
    public Position to() { return to; }
    public Piece captured() { return captured; }
}
