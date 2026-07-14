package chapter38;

/**
 * Strategy — the movement rule for one kind of piece. Given the board and a
 * from/to, decides whether that piece may geometrically make the move
 * (including path blocking and capture rules), NOT whether it leaves the king
 * in check (the Game handles that).
 */
public interface MovementStrategy {
    boolean isValidMove(Board board, Position from, Position to, Color color);
}
