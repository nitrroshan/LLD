package chapter31;

/**
 * A player's mark, or EMPTY for an unplayed cell.
 */
public enum Symbol {
    X,
    O,
    EMPTY;

    @Override
    public String toString() {
        switch (this) {
            case X: return "X";
            case O: return "O";
            default: return ".";
        }
    }
}
