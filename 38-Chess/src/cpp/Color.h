#pragma once

// A player color. White moves up the board (increasing row), Black moves down.
enum class Color { White, Black };

inline Color opposite(Color c) {
    return c == Color::White ? Color::Black : Color::White;
}

inline const char* to_string(Color c) {
    return c == Color::White ? "White" : "Black";
}
