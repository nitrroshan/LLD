package chapter38;

/**
 * Pawn — forward one to an empty square, two from the starting rank, or one
 * diagonally forward to capture an enemy. (En passant and promotion are
 * extensions.)
 */
public class PawnMovementStrategy implements MovementStrategy {
    @Override
    public boolean isValidMove(Board board, Position from, Position to, Color color) {
        int dir = (color == Color.WHITE) ? 1 : -1;
        int startRow = (color == Color.WHITE) ? 1 : 6;
        int dr = to.row() - from.row();
        int dc = to.col() - from.col();

        // Straight advance to an empty square.
        if (dc == 0 && dr == dir && board.isEmpty(to)) {
            return true;
        }
        // Two-square advance from the starting rank, both squares empty.
        if (dc == 0 && dr == 2 * dir && from.row() == startRow) {
            Position between = new Position(from.row() + dir, from.col());
            return board.isEmpty(between) && board.isEmpty(to);
        }
        // Diagonal capture of an enemy piece.
        if (Math.abs(dc) == 1 && dr == dir) {
            Piece target = board.getPiece(to);
            return target != null && target.color() != color;
        }
        return false;
    }
}
