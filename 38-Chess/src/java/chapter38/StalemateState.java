package chapter38;

/** The side to move is not in check but has no legal move — draw. */
public class StalemateState implements GameState {
    private static final StalemateState INSTANCE = new StalemateState();
    private StalemateState() {}
    public static StalemateState instance() { return INSTANCE; }

    @Override public boolean isGameOver() { return true; }
    @Override public String name() { return "STALEMATE"; }
}
