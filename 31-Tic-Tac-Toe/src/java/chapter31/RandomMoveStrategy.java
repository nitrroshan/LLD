package chapter31;

import java.util.List;
import java.util.Random;

/**
 * Concrete Strategy — pick a uniformly random available cell (seeded so demos
 * are reproducible).
 */
public class RandomMoveStrategy implements MoveStrategy {
    private final Random random;

    public RandomMoveStrategy(long seed) {
        this.random = new Random(seed);
    }

    @Override
    public Move chooseMove(Board board, Symbol symbol) {
        List<Move> moves = board.availableMoves();
        return moves.get(random.nextInt(moves.size()));
    }
}
