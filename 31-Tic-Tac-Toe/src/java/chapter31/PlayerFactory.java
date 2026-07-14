package chapter31;

/**
 * Factory Method — builds a Player wired with the right MoveStrategy. (Scripted
 * / human players are constructed directly with a ScriptedMoveStrategy.)
 */
public class PlayerFactory {
    public static Player create(PlayerType type, String name, Symbol symbol, long seed) {
        switch (type) {
            case RANDOM_AI:
                return new Player(name, symbol, new RandomMoveStrategy(seed));
            case SMART_AI:
                return new Player(name, symbol, new RuleBasedAiStrategy());
            default:
                throw new IllegalArgumentException("Unknown player type: " + type);
        }
    }
}
