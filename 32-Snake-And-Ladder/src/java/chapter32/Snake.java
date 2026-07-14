package chapter32;

/**
 * A snake: lands you on a higher cell (head) and drops you to a lower one (tail).
 */
public class Snake extends Jump {
    public Snake(int head, int tail) {
        super(head, tail);
    }

    @Override
    public JumpType getType() {
        return JumpType.SNAKE;
    }
}
