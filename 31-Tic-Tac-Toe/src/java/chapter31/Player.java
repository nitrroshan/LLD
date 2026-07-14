package chapter31;

/**
 * A player is a name + symbol + a move strategy. "Human vs AI" is just two
 * players with different strategies — not different Player subclasses.
 */
public class Player {
    private final String name;
    private final Symbol symbol;
    private final MoveStrategy strategy;

    public Player(String name, Symbol symbol, MoveStrategy strategy) {
        this.name = name;
        this.symbol = symbol;
        this.strategy = strategy;
    }

    public String getName() { return name; }
    public Symbol getSymbol() { return symbol; }

    public Move makeMove(Board board) {
        return strategy.chooseMove(board, symbol);
    }
}
