package chapter38;

/**
 * A player color. White moves up the board (increasing row), Black moves down.
 */
public enum Color {
    WHITE,
    BLACK;

    public Color opposite() {
        return this == WHITE ? BLACK : WHITE;
    }
}
