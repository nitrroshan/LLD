package chapter38;

/**
 * King — one square in any direction. (Castling is an extension.)
 */
public class KingMovementStrategy implements MovementStrategy {
    @Override
    public boolean isValidMove(Board board, Position from, Position to, Color color) {
        int dr = Math.abs(to.row() - from.row());
        int dc = Math.abs(to.col() - from.col());
        if (dr == 0 && dc == 0) return false;
        return dr <= 1 && dc <= 1;
    }
}
