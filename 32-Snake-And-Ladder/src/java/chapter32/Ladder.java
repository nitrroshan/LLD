package chapter32;

/**
 * A ladder: lands you on a lower cell (bottom) and lifts you to a higher one (top).
 */
public class Ladder extends Jump {
    public Ladder(int bottom, int top) {
        super(bottom, top);
    }

    @Override
    public JumpType getType() {
        return JumpType.LADDER;
    }
}
