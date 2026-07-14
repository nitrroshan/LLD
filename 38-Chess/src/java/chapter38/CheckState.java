package chapter38;

/** The side to move is in check but can still play. */
public class CheckState implements GameState {
    private static final CheckState INSTANCE = new CheckState();
    private CheckState() {}
    public static CheckState instance() { return INSTANCE; }

    @Override public boolean isGameOver() { return false; }
    @Override public String name() { return "CHECK"; }
}
