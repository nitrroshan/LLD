#pragma once
#include "Move.h"
#include "Symbol.h"

class Board;  // forward declaration

// Strategy — how a player chooses its next move.
class MoveStrategy {
public:
    virtual ~MoveStrategy() = default;
    virtual Move choose_move(const Board& board, Symbol symbol) = 0;
};
