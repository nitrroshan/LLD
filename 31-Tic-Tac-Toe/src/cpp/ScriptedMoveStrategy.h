#pragma once
#include <deque>
#include <vector>
#include "MoveStrategy.h"
#include "Board.h"

// Concrete Strategy — replays predetermined moves; stands in for human input.
// Falls back to the first available cell if the script runs out.
class ScriptedMoveStrategy : public MoveStrategy {
    std::deque<Move> script_;

public:
    explicit ScriptedMoveStrategy(std::vector<Move> moves)
        : script_(moves.begin(), moves.end()) {}

    Move choose_move(const Board& board, Symbol) override {
        while (!script_.empty()) {
            Move move = script_.front();
            script_.pop_front();
            if (board.is_valid(move)) return move;
        }
        return board.available_moves().front();
    }
};
