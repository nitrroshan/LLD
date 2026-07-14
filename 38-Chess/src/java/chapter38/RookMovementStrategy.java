package chapter38;

/**
 * Rook — any number of squares along a rank or file, path must be clear.
 */
public class RookMovementStrategy implements MovementStrategy {
    @Override
    public boolean isValidMove(Board board, Position from, Position to, Color color) {
        boolean straight = from.row() == to.row() || from.col() == to.col();
        if (!straight || from.equals(to)) return false;
        return board.isPathClear(from, to);
    }
}
