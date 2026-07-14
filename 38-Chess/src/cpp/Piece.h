#pragma once
#include "Color.h"
#include "PieceType.h"
#include "Position.h"
#include "MovementStrategy.h"

class Board;

// A chess piece: color + type + its movement Strategy (a shared singleton).
class Piece {
    Color color_;
    PieceType type_;
    const MovementStrategy* strategy_;
    bool has_moved_ = false;

public:
    Piece(Color color, PieceType type, const MovementStrategy* strategy)
        : color_(color), type_(type), strategy_(strategy) {}

    bool can_move(const Board& board, const Position& from, const Position& to) const {
        return strategy_->is_valid_move(board, from, to, color_);
    }

    Color color() const { return color_; }
    PieceType type() const { return type_; }
    bool has_moved() const { return has_moved_; }
    void set_moved(bool moved) { has_moved_ = moved; }

    char glyph() const {
        char s = symbol(type_);
        return color_ == Color::White ? s : static_cast<char>(s - 'A' + 'a');
    }
};
