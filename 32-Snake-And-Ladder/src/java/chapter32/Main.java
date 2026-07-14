package chapter32;

import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Snake & Ladder Demo ===\n");

        int size = 25;
        Board board = new Board(size);

        // Ladders (go up) and snakes (go down), all factory-validated.
        board.addJump(BoardEntityFactory.createLadder(3, 11, size));
        board.addJump(BoardEntityFactory.createLadder(6, 17, size));
        board.addJump(BoardEntityFactory.createLadder(9, 21, size));
        board.addJump(BoardEntityFactory.createSnake(16, 4, size));
        board.addJump(BoardEntityFactory.createSnake(20, 7, size));
        board.addJump(BoardEntityFactory.createSnake(24, 10, size));

        Dice dice = new Dice(6, 1, 42);

        List<Player> players = Arrays.asList(new Player("Alice"), new Player("Bob"));

        Game game = new Game(board, dice, players);
        game.addListener(new ConsoleGameLogger());   // Observer 1: play-by-play
        game.addListener(new StatisticsTracker());    // Observer 2: aggregate stats

        System.out.println("Board size " + size + ", 3 ladders, 3 snakes, 2 players\n");
        game.play(200);

        // Try an invalid board element — the factory rejects it.
        System.out.println("\nValidating board elements:");
        try {
            BoardEntityFactory.createLadder(20, 5, size);   // a ladder that goes down!
        } catch (IllegalArgumentException e) {
            System.out.println("  Rejected: " + e.getMessage());
        }
    }
}
