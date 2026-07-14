#pragma once

// A player's mark, or Empty for an unplayed cell.
enum class Symbol { X, O, Empty };

inline const char* to_string(Symbol s) {
    switch (s) {
        case Symbol::X: return "X";
        case Symbol::O: return "O";
        default:        return ".";
    }
}
