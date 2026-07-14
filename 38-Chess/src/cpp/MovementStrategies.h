#pragma once
#include <cstdlib>
#include "MovementStrategy.h"
#include "Board.h"
#include "Piece.h"

// Concrete movement rules as stateless singletons (one shared per piece type).

class KingMovementStrategy : public MovementStrategy {
public:
    static const KingMovementStrategy& instance() { static KingMovementStrategy s; return s; }
    bool is_valid_move(const Board&, const Position& from, const Position& to, Color) const override {
        int dr = std::abs(to.row - from.row), dc = std::abs(to.col - from.col);
        if (dr == 0 && dc == 0) return false;
        return dr <= 1 && dc <= 1;
    }
};

class RookMovementStrategy : public MovementStrategy {
public:
    static const RookMovementStrategy& instance() { static RookMovementStrategy s; return s; }
    bool is_valid_move(const Board& board, const Position& from, const Position& to, Color) const override {
        bool straight = from.row == to.row || from.col == to.col;
        if (!straight || from == to) return false;
        return board.is_path_clear(from, to);
    }
};

class BishopMovementStrategy : public MovementStrategy {
public:
    static const BishopMovementStrategy& instance() { static BishopMovementStrategy s; return s; }
    bool is_valid_move(const Board& board, const Position& from, const Position& to, Color) const override {
        int dr = std::abs(to.row - from.row), dc = std::abs(to.col - from.col);
        if (dr != dc || dr == 0) return false;
        return board.is_path_clear(from, to);
    }
};

class QueenMovementStrategy : public MovementStrategy {
public:
    static const QueenMovementStrategy& instance() { static QueenMovementStrategy s; return s; }
    bool is_valid_move(const Board& board, const Position& from, const Position& to, Color color) const override {
        return RookMovementStrategy::instance().is_valid_move(board, from, to, color)
            || BishopMovementStrategy::instance().is_valid_move(board, from, to, color);
    }
};

class KnightMovementStrategy : public MovementStrategy {
public:
    static const KnightMovementStrategy& instance() { static KnightMovementStrategy s; return s; }
    bool is_valid_move(const Board&, const Position& from, const Position& to, Color) const override {
        int dr = std::abs(to.row - from.row), dc = std::abs(to.col - from.col);
        return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
    }
};

class PawnMovementStrategy : public MovementStrategy {
public:
    static const PawnMovementStrategy& instance() { static PawnMovementStrategy s; return s; }
    bool is_valid_move(const Board& board, const Position& from, const Position& to, Color color) const override {
        int dir = (color == Color::White) ? 1 : -1;
        int start_row = (color == Color::White) ? 1 : 6;
        int dr = to.row - from.row, dc = to.col - from.col;

        if (dc == 0 && dr == dir && board.is_empty(to)) return true;               // advance one
        if (dc == 0 && dr == 2 * dir && from.row == start_row) {                    // advance two
            Position between{from.row + dir, from.col};
            return board.is_empty(between) && board.is_empty(to);
        }
        if (std::abs(dc) == 1 && dr == dir) {                                       // diagonal capture
            Piece* target = board.get_piece(to);
            return target != nullptr && target->color() != color;
        }
        return false;
    }
};
