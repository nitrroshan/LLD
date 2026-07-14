package chapter38;

/**
 * The 8x8 board. Owns the pieces, moves them, and provides the primitives the
 * rest of the engine needs: path clearing, finding a king, and detecting
 * whether a square is attacked (the basis of check detection).
 */
public class Board {
    private final Piece[][] grid = new Piece[8][8];

    public Piece getPiece(Position p) {
        return grid[p.row()][p.col()];
    }

    public void setPiece(Position p, Piece piece) {
        grid[p.row()][p.col()] = piece;
    }

    public boolean isEmpty(Position p) {
        return grid[p.row()][p.col()] == null;
    }

    /**
     * Moves the piece from -> to and returns whatever was captured (or null).
     * Pure board mutation; legality is decided elsewhere.
     */
    public Piece movePiece(Position from, Position to) {
        Piece moving = grid[from.row()][from.col()];
        Piece captured = grid[to.row()][to.col()];
        grid[to.row()][to.col()] = moving;
        grid[from.row()][from.col()] = null;
        return captured;
    }

    /** Straight-line (rook/bishop/queen) path check, endpoints exclusive. */
    public boolean isPathClear(Position from, Position to) {
        int dr = Integer.signum(to.row() - from.row());
        int dc = Integer.signum(to.col() - from.col());
        int r = from.row() + dr;
        int c = from.col() + dc;
        while (r != to.row() || c != to.col()) {
            if (grid[r][c] != null) return false;
            r += dr;
            c += dc;
        }
        return true;
    }

    public Position findKing(Color color) {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                Piece p = grid[r][c];
                if (p != null && p.type() == PieceType.KING && p.color() == color) {
                    return new Position(r, c);
                }
            }
        }
        return null; // shouldn't happen in a legal game
    }

    /**
     * Is {@code square} attacked by any piece of {@code byColor}? Used for
     * check detection. Works because check tests are run when the square holds
     * the (enemy) king, so pawn diagonal-capture rules apply correctly.
     */
    public boolean isSquareAttacked(Position square, Color byColor) {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                Piece p = grid[r][c];
                if (p != null && p.color() == byColor) {
                    Position from = new Position(r, c);
                    if (!from.equals(square) && p.canMove(this, from, square)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public void print() {
        for (int r = 7; r >= 0; r--) {
            System.out.print("  " + (r + 1) + " ");
            for (int c = 0; c < 8; c++) {
                Piece p = grid[r][c];
                System.out.print((p == null ? "." : p.toString()) + " ");
            }
            System.out.println();
        }
        System.out.println("    a b c d e f g h");
    }
}
