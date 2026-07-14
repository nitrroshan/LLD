package chapter38;

/**
 * A chess piece: a color and type, plus its movement Strategy. Movement is
 * delegated to the strategy so each rule-set lives in its own class.
 */
public class Piece {
    private final Color color;
    private final PieceType type;
    private final MovementStrategy strategy;
    private boolean hasMoved = false;

    public Piece(Color color, PieceType type, MovementStrategy strategy) {
        this.color = color;
        this.type = type;
        this.strategy = strategy;
    }

    public boolean canMove(Board board, Position from, Position to) {
        return strategy.isValidMove(board, from, to, color);
    }

    public Color color() { return color; }
    public PieceType type() { return type; }
    public boolean hasMoved() { return hasMoved; }
    public void setMoved(boolean moved) { this.hasMoved = moved; }

    @Override
    public String toString() {
        char c = type.symbol();
        return color == Color.WHITE ? ("" + c) : ("" + Character.toLowerCase(c));
    }
}
