#include <iostream>
#include <memory>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "PlayerFactory.h"
#include "ScriptedMoveStrategy.h"
#include "Game.h"

int main() {
    std::cout << "=== Tic-Tac-Toe Demo (C++) ===\n\n";

    // Game 1: two scripted players (stand-in for human vs human). X wins the top row.
    std::cout << "Game 1: Alice (X, scripted) vs Bob (O, scripted)\n";
    Player alice("Alice", Symbol::X,
                 std::make_unique<ScriptedMoveStrategy>(std::vector<Move>{{0, 0}, {0, 1}, {0, 2}}));
    Player bob("Bob", Symbol::O,
               std::make_unique<ScriptedMoveStrategy>(std::vector<Move>{{1, 0}, {1, 1}}));
    Game game1(Board(3), alice, bob);
    game1.play();

    // Game 2: Smart AI vs Random AI (Factory-built), deterministic via seed.
    std::cout << "\nGame 2: Smart AI (X) vs Random AI (O)\n";
    Player smart = PlayerFactory::create(PlayerType::SmartAi, "SmartBot", Symbol::X, 0);
    Player rando = PlayerFactory::create(PlayerType::RandomAi, "RandoBot", Symbol::O, 42);
    Game game2(Board(3), smart, rando);
    game2.play();

    std::cout << "\nSame Game and Player classes drove both matches -\n";
    std::cout << "only the plugged-in MoveStrategy differed.\n";

    return 0;
}
