#pragma once
#include <iostream>
#include "GameEventListener.h"

// Concrete Observer — tracks aggregate statistics. Shows multiple observers
// reacting to the same events.
class StatisticsTracker : public GameEventListener {
    int total_moves_ = 0;
    int snakes_hit_ = 0;
    int ladders_climbed_ = 0;

public:
    void on_move(const Player&, int, int, int) override { total_moves_++; }

    void on_jump(const Player&, JumpType type, int, int) override {
        if (type == JumpType::Snake) snakes_hit_++;
        else ladders_climbed_++;
    }

    void on_skip(const Player&, int) override {}

    void on_win(const Player&) override {
        std::cout << "  --- Stats ---\n";
        std::cout << "    Total moves:      " << total_moves_ << "\n";
        std::cout << "    Ladders climbed:  " << ladders_climbed_ << "\n";
        std::cout << "    Snakes hit:       " << snakes_hit_ << "\n";
    }
};
