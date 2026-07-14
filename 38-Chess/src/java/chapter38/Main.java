package chapter38;

/**
 * Demo — plays Scholar's Mate (a 4-move checkmate) to exercise the Strategy
 * movement rules, Command-based moves/undo, State transitions, and Observer
 * notifications; then a short pin scenario to show a king-safety rejection.
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== Chess Game Demo (Java) ===\n");

        Game game = new Game();
        game.addObserver(new ConsoleGameObserver());

        System.out.println("Starting position:");
        game.board().print();

        // An illegal move: the queen's path is blocked by its own pawn.
        System.out.println("\nIllegal move attempt (Qd1-d3, blocked):");
        game.makeMove(pos("d1"), pos("d3"));

        // Scholar's Mate.
        System.out.println("\nScholar's Mate:");
        game.makeMove(pos("e2"), pos("e4"));   // 1. e4
        game.makeMove(pos("e7"), pos("e5"));   // 1... e5

        // Demonstrate undo, then replay.
        System.out.println("  (undo and replay the last move)");
        game.undo();
        game.makeMove(pos("e7"), pos("e5"));

        game.makeMove(pos("f1"), pos("c4"));   // 2. Bc4
        game.makeMove(pos("b8"), pos("c6"));   // 2... Nc6
        game.makeMove(pos("d1"), pos("h5"));   // 3. Qh5
        game.makeMove(pos("g8"), pos("f6"));   // 3... Nf6?? (blunder)
        game.makeMove(pos("h5"), pos("f7"));   // 4. Qxf7#

        System.out.println("\nFinal position (" + game.state().name() + "):");
        game.board().print();

        // A second game: a pinned knight cannot legally move (king-safety).
        System.out.println("\n=== King-safety (pin) demo ===");
        Game pin = new Game();
        pin.addObserver(new ConsoleGameObserver());
        pin.makeMove(pos("e2"), pos("e4"));
        pin.makeMove(pos("d7"), pos("d6"));    // vacate d7
        pin.makeMove(pos("f1"), pos("b5"));    // bishop checks along b5-e8
        pin.makeMove(pos("b8"), pos("c6"));    // knight blocks — and is now pinned
        pin.makeMove(pos("a2"), pos("a4"));
        System.out.println("Black tries to move the pinned knight (Nc6-d4):");
        pin.makeMove(pos("c6"), pos("d4"));    // rejected — exposes the king
    }

    private static Position pos(String square) {
        int col = square.charAt(0) - 'a';
        int row = square.charAt(1) - '1';
        return new Position(row, col);
    }
}
