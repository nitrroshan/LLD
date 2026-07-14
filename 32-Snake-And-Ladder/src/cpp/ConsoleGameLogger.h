#pragma once
#include <iostream>
#include "GameEventListener.h"

// Concrete Observer — prints a play-by-play of the game.
class ConsoleGameLogger : public GameEventListener {
public:
    void on_move(const Player& player, int from, int to, int dice_value) override {
        std::cout << "  " << player.name() << " rolled " << dice_value
                  << ": " << from << " -> " << to << "\n";
    }

    void on_jump(const Player& player, JumpType type, int from, int to) override {
        if (type == JumpType::Ladder) {
            std::cout << "    Ladder! " << player.name() << " climbs " << from << " -> " << to << "\n";
        } else {
            std::cout << "    Snake! " << player.name() << " slides " << from << " -> " << to << "\n";
        }
    }

    void on_skip(const Player& player, int dice_value) override {
        std::cout << "  " << player.name() << " rolled " << dice_value
                  << " but would overshoot - stays put\n";
    }

    void on_win(const Player& player) override {
        std::cout << "  " << player.name() << " reached the final cell and WINS!\n";
    }
};
