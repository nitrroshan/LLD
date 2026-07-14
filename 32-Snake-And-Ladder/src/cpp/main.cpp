#include <iostream>
#include <vector>
#include <stdexcept>
#include "Board.h"
#include "BoardEntityFactory.h"
#include "Dice.h"
#include "Player.h"
#include "ConsoleGameLogger.h"
#include "StatisticsTracker.h"
#include "Game.h"

int main() {
    std::cout << "=== Snake & Ladder Demo (C++) ===\n\n";

    int size = 25;
    Board board(size);

    // Ladders (up) and snakes (down), all factory-validated.
    board.add_jump(BoardEntityFactory::create_ladder(3, 11, size));
    board.add_jump(BoardEntityFactory::create_ladder(6, 17, size));
    board.add_jump(BoardEntityFactory::create_ladder(9, 21, size));
    board.add_jump(BoardEntityFactory::create_snake(16, 4, size));
    board.add_jump(BoardEntityFactory::create_snake(20, 7, size));
    board.add_jump(BoardEntityFactory::create_snake(24, 10, size));

    Dice dice(6, 1, 42);

    Player alice("Alice");
    Player bob("Bob");
    std::vector<Player*> players = {&alice, &bob};

    Game game(board, dice, players);
    ConsoleGameLogger logger;
    StatisticsTracker stats;
    game.add_listener(&logger);   // Observer 1: play-by-play
    game.add_listener(&stats);    // Observer 2: aggregate stats

    std::cout << "Board size " << size << ", 3 ladders, 3 snakes, 2 players\n\n";
    game.play(200);

    // Try an invalid board element — the factory rejects it.
    std::cout << "\nValidating board elements:\n";
    try {
        BoardEntityFactory::create_ladder(20, 5, size);   // a ladder that goes down!
    } catch (const std::invalid_argument& e) {
        std::cout << "  Rejected: " << e.what() << "\n";
    }

    return 0;
}
