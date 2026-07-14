package chapter38;

/**
 * Queen — combines rook and bishop movement.
 */
public class QueenMovementStrategy implements MovementStrategy {
    private final MovementStrategy rook = new RookMovementStrategy();
    private final MovementStrategy bishop = new BishopMovementStrategy();

    @Override
    public boolean isValidMove(Board board, Position from, Position to, Color color) {
        return rook.isValidMove(board, from, to, color)
                || bishop.isValidMove(board, from, to, color);
    }
}
