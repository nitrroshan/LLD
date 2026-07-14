#pragma once
#include <random>
#include <vector>
#include "MoveStrategy.h"
#include "Board.h"

// Concrete Strategy — pick a uniformly random available cell (seeded).
class RandomMoveStrategy : public MoveStrategy {
    std::mt19937 rng_;

public:
    explicit RandomMoveStrategy(unsigned long seed) : rng_(seed) {}

    Move choose_move(const Board& board, Symbol) override {
        std::vector<Move> moves = board.available_moves();
        std::uniform_int_distribution<std::size_t> dist(0, moves.size() - 1);
        return moves[dist(rng_)];
    }
};
