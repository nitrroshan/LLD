package chapter38;

/**
 * Knight — L-shape (2,1); jumps over pieces so no path check.
 */
public class KnightMovementStrategy implements MovementStrategy {
    @Override
    public boolean isValidMove(Board board, Position from, Position to, Color color) {
        int dr = Math.abs(to.row() - from.row());
        int dc = Math.abs(to.col() - from.col());
        return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
    }
}
