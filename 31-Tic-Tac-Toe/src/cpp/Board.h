#pragma once
#include <vector>
#include <iostream>
#include "Symbol.h"
#include "Move.h"

// An N x N board. Detects a winner (full row / column / diagonal of one symbol),
// lists available moves, and can be copied for AI look-ahead.
class Board {
    int size_;
    std::vector<std::vector<Symbol>> grid_;

    Symbol line_winner(int start_row, int start_col, int d_row, int d_col) const {
        Symbol first = grid_[start_row][start_col];
        if (first == Symbol::Empty) return Symbol::Empty;
        int r = start_row, c = start_col;
        for (int i = 0; i < size_; i++) {
            if (grid_[r][c] != first) return Symbol::Empty;
            r += d_row;
            c += d_col;
        }
        return first;
    }

public:
    explicit Board(int size)
        : size_(size), grid_(size, std::vector<Symbol>(size, Symbol::Empty)) {}

    int size() const { return size_; }
    Symbol get(int row, int col) const { return grid_[row][col]; }

    bool is_valid(const Move& move) const {
        return move.row >= 0 && move.row < size_ && move.col >= 0 && move.col < size_
               && grid_[move.row][move.col] == Symbol::Empty;
    }

    void place_mark(const Move& move, Symbol symbol) {
        grid_[move.row][move.col] = symbol;
    }

    std::vector<Move> available_moves() const {
        std::vector<Move> moves;
        for (int r = 0; r < size_; r++) {
            for (int c = 0; c < size_; c++) {
                if (grid_[r][c] == Symbol::Empty) {
                    moves.push_back(Move{r, c});
                }
            }
        }
        return moves;
    }

    bool is_full() const { return available_moves().empty(); }

    Symbol get_winner() const {
        for (int i = 0; i < size_; i++) {
            Symbol row = line_winner(i, 0, 0, 1);
            if (row != Symbol::Empty) return row;
            Symbol col = line_winner(0, i, 1, 0);
            if (col != Symbol::Empty) return col;
        }
        Symbol diag = line_winner(0, 0, 1, 1);
        if (diag != Symbol::Empty) return diag;
        Symbol anti = line_winner(0, size_ - 1, 1, -1);
        if (anti != Symbol::Empty) return anti;
        return Symbol::Empty;
    }

    Board copy() const { return *this; }

    void display() const {
        for (int r = 0; r < size_; r++) {
            std::cout << "  ";
            for (int c = 0; c < size_; c++) {
                std::cout << to_string(grid_[r][c]);
                if (c < size_ - 1) std::cout << " ";
            }
            std::cout << "\n";
        }
    }
};
