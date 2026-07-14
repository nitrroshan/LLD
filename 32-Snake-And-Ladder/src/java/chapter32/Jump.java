package chapter32;

/**
 * A relocation on the board from a start cell to an end cell. Snakes and
 * ladders are both jumps — they differ only in direction and label.
 */
public abstract class Jump {
    private final int start;
    private final int end;

    protected Jump(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public int getStart() { return start; }
    public int getEnd() { return end; }

    public abstract JumpType getType();
}
