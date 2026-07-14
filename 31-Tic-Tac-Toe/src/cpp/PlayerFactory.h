#pragma once
#include <string>
#include <memory>
#include <stdexcept>
#include "Player.h"
#include "RandomMoveStrategy.h"
#include "RuleBasedAiStrategy.h"

enum class PlayerType { RandomAi, SmartAi };

// Factory Method — builds a Player wired with the right MoveStrategy.
class PlayerFactory {
public:
    static Player create(PlayerType type, const std::string& name, Symbol symbol,
                         unsigned long seed) {
        switch (type) {
            case PlayerType::RandomAi:
                return Player(name, symbol, std::make_unique<RandomMoveStrategy>(seed));
            case PlayerType::SmartAi:
                return Player(name, symbol, std::make_unique<RuleBasedAiStrategy>());
        }
        throw std::invalid_argument("Unknown player type");
    }
};
