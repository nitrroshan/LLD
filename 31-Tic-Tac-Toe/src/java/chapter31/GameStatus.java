package chapter31;

/**
 * Outcome of the game. Governs whether play continues (a State modeled as an enum).
 */
public enum GameStatus {
    IN_PROGRESS,
    X_WINS,
    O_WINS,
    DRAW
}
