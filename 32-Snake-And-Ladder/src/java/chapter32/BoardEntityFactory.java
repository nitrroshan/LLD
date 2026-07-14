package chapter32;

/**
 * Factory Method — creates and VALIDATES board elements. A snake must go down,
 * a ladder must go up, and both must stay within the board.
 */
public class BoardEntityFactory {
    public static Snake createSnake(int head, int tail, int boardSize) {
        if (head <= tail) {
            throw new IllegalArgumentException("Snake head (" + head + ") must be above its tail (" + tail + ")");
        }
        validateBounds(head, boardSize);
        validateBounds(tail, boardSize);
        return new Snake(head, tail);
    }

    public static Ladder createLadder(int bottom, int top, int boardSize) {
        if (bottom >= top) {
            throw new IllegalArgumentException("Ladder bottom (" + bottom + ") must be below its top (" + top + ")");
        }
        validateBounds(bottom, boardSize);
        validateBounds(top, boardSize);
        return new Ladder(bottom, top);
    }

    private static void validateBounds(int cell, int boardSize) {
        if (cell < 1 || cell > boardSize) {
            throw new IllegalArgumentException("Cell " + cell + " is outside the board (1.." + boardSize + ")");
        }
    }
}
