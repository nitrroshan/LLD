#pragma once
#include <string>

// A square on the board: row and column in 0..7. Row 0 is White's back rank.
struct Position {
    int row = 0;
    int col = 0;

    Position() = default;
    Position(int r, int c) : row(r), col(c) {}

    static bool is_inside(int r, int c) {
        return r >= 0 && r < 8 && c >= 0 && c < 8;
    }

    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
    bool operator!=(const Position& other) const { return !(*this == other); }

    std::string to_string() const {
        std::string s;
        s += static_cast<char>('a' + col);
        s += static_cast<char>('1' + row);
        return s;
    }
};
