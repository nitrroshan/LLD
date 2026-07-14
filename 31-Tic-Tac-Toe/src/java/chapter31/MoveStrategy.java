package chapter31;

/**
 * Strategy — how a player chooses its next move.
 */
public interface MoveStrategy {
    Move chooseMove(Board board, Symbol symbol);
}
