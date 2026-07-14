#pragma once
#include <memory>
#include <stdexcept>
#include <string>
#include "Snake.h"
#include "Ladder.h"

// Factory Method — creates and VALIDATES board elements. A snake must go down,
// a ladder must go up, and both must stay within the board.
class BoardEntityFactory {
    static void validate_bounds(int cell, int board_size) {
        if (cell < 1 || cell > board_size) {
            throw std::invalid_argument("Cell " + std::to_string(cell) +
                                        " is outside the board (1.." + std::to_string(board_size) + ")");
        }
    }

public:
    static std::unique_ptr<Snake> create_snake(int head, int tail, int board_size) {
        if (head <= tail) {
            throw std::invalid_argument("Snake head (" + std::to_string(head) +
                                        ") must be above its tail (" + std::to_string(tail) + ")");
        }
        validate_bounds(head, board_size);
        validate_bounds(tail, board_size);
        return std::make_unique<Snake>(head, tail);
    }

    static std::unique_ptr<Ladder> create_ladder(int bottom, int top, int board_size) {
        if (bottom >= top) {
            throw std::invalid_argument("Ladder bottom (" + std::to_string(bottom) +
                                        ") must be below its top (" + std::to_string(top) + ")");
        }
        validate_bounds(bottom, board_size);
        validate_bounds(top, board_size);
        return std::make_unique<Ladder>(bottom, top);
    }
};
