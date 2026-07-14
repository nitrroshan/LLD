package chapter38;

/** The side to move is in check with no legal move — game over. */
public class CheckmateState implements GameState {
    private static final CheckmateState INSTANCE = new CheckmateState();
    private CheckmateState() {}
    public static CheckmateState instance() { return INSTANCE; }

    @Override public boolean isGameOver() { return true; }
    @Override public String name() { return "CHECKMATE"; }
}
