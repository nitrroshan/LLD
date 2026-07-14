package chapter38;

/**
 * Factory — builds a piece wired to its movement strategy. The strategies are
 * stateless, so one shared instance per type is reused by every piece.
 */
public class PieceFactory {
    private static final MovementStrategy KING = new KingMovementStrategy();
    private static final MovementStrategy QUEEN = new QueenMovementStrategy();
    private static final MovementStrategy ROOK = new RookMovementStrategy();
    private static final MovementStrategy BISHOP = new BishopMovementStrategy();
    private static final MovementStrategy KNIGHT = new KnightMovementStrategy();
    private static final MovementStrategy PAWN = new PawnMovementStrategy();

    public static Piece create(Color color, PieceType type) {
        MovementStrategy strategy = switch (type) {
            case KING -> KING;
            case QUEEN -> QUEEN;
            case ROOK -> ROOK;
            case BISHOP -> BISHOP;
            case KNIGHT -> KNIGHT;
            case PAWN -> PAWN;
        };
        return new Piece(color, type, strategy);
    }
}
