package chapter38;

/** Normal play in progress. */
public class ActiveState implements GameState {
    private static final ActiveState INSTANCE = new ActiveState();
    private ActiveState() {}
    public static ActiveState instance() { return INSTANCE; }

    @Override public boolean isGameOver() { return false; }
    @Override public String name() { return "ACTIVE"; }
}
