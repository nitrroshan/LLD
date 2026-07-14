package chapter31;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.List;

/**
 * Concrete Strategy — replays a predetermined list of moves. Stands in for a
 * human's typed input in a deterministic demo. If the script runs out, it
 * falls back to the first available cell.
 */
public class ScriptedMoveStrategy implements MoveStrategy {
    private final Deque<Move> script = new ArrayDeque<>();

    public ScriptedMoveStrategy(List<Move> moves) {
        script.addAll(moves);
    }

    @Override
    public Move chooseMove(Board board, Symbol symbol) {
        while (!script.isEmpty()) {
            Move move = script.poll();
            if (board.isValid(move)) {
                return move;
            }
        }
        return board.availableMoves().get(0);
    }
}
