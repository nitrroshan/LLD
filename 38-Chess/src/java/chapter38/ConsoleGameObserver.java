package chapter38;

/**
 * Observer — prints game events to the console.
 */
public class ConsoleGameObserver implements GameObserver {
    @Override
    public void onMove(Position from, Position to, Piece moved, Piece captured) {
        String text = "  " + moved + " " + from + "->" + to;
        if (captured != null) text += " captures " + captured;
        System.out.println(text);
    }

    @Override
    public void onCheck(Color inCheck) {
        System.out.println("  >> " + inCheck + " is in CHECK");
    }

    @Override
    public void onCheckmate(Color winner) {
        System.out.println("  >> CHECKMATE — " + winner + " wins!");
    }

    @Override
    public void onStalemate() {
        System.out.println("  >> STALEMATE — draw");
    }
}
