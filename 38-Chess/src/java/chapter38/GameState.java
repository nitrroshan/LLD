package chapter38;

/**
 * State — the game's status. Governs whether further moves are allowed.
 */
public interface GameState {
    boolean isGameOver();
    String name();
}
