package chapter31;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Tic-Tac-Toe Demo ===\n");

        // Game 1: two scripted players (stand-in for human vs human). X wins the top row.
        System.out.println("Game 1: Alice (X, scripted) vs Bob (O, scripted)");
        Player alice = new Player("Alice", Symbol.X, new ScriptedMoveStrategy(Arrays.asList(
                new Move(0, 0), new Move(0, 1), new Move(0, 2))));
        Player bob = new Player("Bob", Symbol.O, new ScriptedMoveStrategy(Arrays.asList(
                new Move(1, 0), new Move(1, 1))));
        new Game(new Board(3), alice, bob).play();

        // Game 2: Smart AI vs Random AI (Factory-built), deterministic via seed.
        System.out.println("\nGame 2: Smart AI (X) vs Random AI (O)");
        Player smart = PlayerFactory.create(PlayerType.SMART_AI, "SmartBot", Symbol.X, 0);
        Player rando = PlayerFactory.create(PlayerType.RANDOM_AI, "RandoBot", Symbol.O, 42);
        new Game(new Board(3), smart, rando).play();

        System.out.println("\nSame Game and Player classes drove both matches —");
        System.out.println("only the plugged-in MoveStrategy differed.");
    }
}
