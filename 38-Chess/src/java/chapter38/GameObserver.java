package chapter38;

/**
 * Observer — reacts to game events without the game knowing the listener type.
 */
public interface GameObserver {
    void onMove(Position from, Position to, Piece moved, Piece captured);
    void onCheck(Color inCheck);
    void onCheckmate(Color winner);
    void onStalemate();
}
