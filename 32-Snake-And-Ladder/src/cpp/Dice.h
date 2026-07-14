#pragma once
#include <random>

// A die (or dice). Configurable faces and count; seeded for reproducible demos.
class Dice {
    int faces_;
    int count_;
    std::mt19937 rng_;

public:
    Dice(int faces, int count, unsigned long seed)
        : faces_(faces), count_(count), rng_(seed) {}

    int roll() {
        std::uniform_int_distribution<int> dist(1, faces_);
        int total = 0;
        for (int i = 0; i < count_; i++) {
            total += dist(rng_);
        }
        return total;
    }

    int max_roll() const { return faces_ * count_; }
};
