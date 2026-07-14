#include <iostream>
#include <string>
#include "Game.h"
#include "ConsoleGameObserver.h"

// Parse algebraic notation like "e2" into a Position.
static Position pos(const std::string& square) {
    int col = square[0] - 'a';
    int row = square[1] - '1';
    return {row, col};
}

int main() {
    std::cout << "=== Chess Game Demo (C++) ===\n\n";

    Game game;
    ConsoleGameObserver observer;
    game.add_observer(&observer);

    std::cout << "Starting position:\n";
    game.board().print();

    // An illegal move: the queen's path is blocked by its own pawn.
    std::cout << "\nIllegal move attempt (Qd1-d3, blocked):\n";
    game.make_move(pos("d1"), pos("d3"));

    // Scholar's Mate.
    std::cout << "\nScholar's Mate:\n";
    game.make_move(pos("e2"), pos("e4"));   // 1. e4
    game.make_move(pos("e7"), pos("e5"));   // 1... e5

    // Demonstrate undo, then replay.
    std::cout << "  (undo and replay the last move)\n";
    game.undo();
    game.make_move(pos("e7"), pos("e5"));

    game.make_move(pos("f1"), pos("c4"));   // 2. Bc4
    game.make_move(pos("b8"), pos("c6"));   // 2... Nc6
    game.make_move(pos("d1"), pos("h5"));   // 3. Qh5
    game.make_move(pos("g8"), pos("f6"));   // 3... Nf6?? (blunder)
    game.make_move(pos("h5"), pos("f7"));   // 4. Qxf7#

    std::cout << "\nFinal position (" << game.state()->name() << "):\n";
    game.board().print();

    // A second game: a pinned knight cannot legally move (king-safety).
    std::cout << "\n=== King-safety (pin) demo ===\n";
    Game pin;
    ConsoleGameObserver pin_observer;
    pin.add_observer(&pin_observer);
    pin.make_move(pos("e2"), pos("e4"));
    pin.make_move(pos("d7"), pos("d6"));    // vacate d7
    pin.make_move(pos("f1"), pos("b5"));    // bishop checks along b5-e8
    pin.make_move(pos("b8"), pos("c6"));    // knight blocks — and is now pinned
    pin.make_move(pos("a2"), pos("a4"));
    std::cout << "Black tries to move the pinned knight (Nc6-d4):\n";
    pin.make_move(pos("c6"), pos("d4"));    // rejected — exposes the king

    return 0;
}
