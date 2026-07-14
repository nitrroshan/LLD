#pragma once
#include "Color.h"
#include "Position.h"

class Board;

// Strategy — the movement rule for one kind of piece. Decides whether the piece
// may geometrically make the move (path, capture rules), NOT king safety.
class MovementStrategy {
public:
    virtual ~MovementStrategy() = default;
    virtual bool is_valid_move(const Board& board, const Position& from,
                               const Position& to, Color color) const = 0;
};
