#pragma once
#include <array>
#include <memory>
#include <iostream>
#include "Piece.h"
#include "Position.h"
#include "Color.h"
#include "PieceType.h"

// The 8x8 board. Owns the pieces (unique_ptr per square) and provides the
// primitives the engine needs: path clearing, finding a king, and attack
// detection (the basis of check detection).
class Board {
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> grid_;

    static int sign(int x) { return (x > 0) - (x < 0); }

public:
    Piece* get_piece(const Position& p) const { return grid_[p.row][p.col].get(); }
    void set_piece(const Position& p, std::unique_ptr<Piece> piece) { grid_[p.row][p.col] = std::move(piece); }
    bool is_empty(const Position& p) const { return grid_[p.row][p.col] == nullptr; }

    // Moves from -> to and returns whatever was captured (or nullptr). The
    // caller (a MoveCommand) takes ownership of the captured piece.
    std::unique_ptr<Piece> move_piece(const Position& from, const Position& to) {
        std::unique_ptr<Piece> captured = std::move(grid_[to.row][to.col]);
        grid_[to.row][to.col] = std::move(grid_[from.row][from.col]);
        return captured;
    }

    // Straight-line (rook/bishop/queen) path check, endpoints exclusive.
    bool is_path_clear(const Position& from, const Position& to) const {
        int dr = sign(to.row - from.row);
        int dc = sign(to.col - from.col);
        int r = from.row + dr, c = from.col + dc;
        while (r != to.row || c != to.col) {
            if (grid_[r][c] != nullptr) return false;
            r += dr;
            c += dc;
        }
        return true;
    }

    Position find_king(Color color) const {
        for (int r = 0; r < 8; r++)
            for (int c = 0; c < 8; c++) {
                Piece* p = grid_[r][c].get();
                if (p && p->type() == PieceType::King && p->color() == color) return {r, c};
            }
        return {-1, -1};
    }

    // Is `square` attacked by any piece of `byColor`? Correct for check detection
    // because such tests run when `square` holds the (enemy) king.
    bool is_square_attacked(const Position& square, Color byColor) const {
        for (int r = 0; r < 8; r++)
            for (int c = 0; c < 8; c++) {
                Piece* p = grid_[r][c].get();
                if (p && p->color() == byColor) {
                    Position from{r, c};
                    if (from != square && p->can_move(*this, from, square)) return true;
                }
            }
        return false;
    }

    void print() const {
        for (int r = 7; r >= 0; r--) {
            std::cout << "  " << (r + 1) << " ";
            for (int c = 0; c < 8; c++) {
                Piece* p = grid_[r][c].get();
                std::cout << (p ? p->glyph() : '.') << ' ';
            }
            std::cout << "\n";
        }
        std::cout << "    a b c d e f g h\n";
    }
};
