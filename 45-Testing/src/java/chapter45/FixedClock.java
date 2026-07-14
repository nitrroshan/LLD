package chapter45;

/** A fixed clock for deterministic tests. */
public class FixedClock implements Clock {
    private final long fixed;
    public FixedClock(long fixed) { this.fixed = fixed; }
    @Override public long now() { return fixed; }
}
