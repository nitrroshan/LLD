package chapter38;

/**
 * Bishop — any number of squares diagonally, path must be clear.
 */
public class BishopMovementStrategy implements MovementStrategy {
    @Override
    public boolean isValidMove(Board board, Position from, Position to, Color color) {
        int dr = Math.abs(to.row() - from.row());
        int dc = Math.abs(to.col() - from.col());
        if (dr != dc || dr == 0) return false;
        return board.isPathClear(from, to);
    }
}
