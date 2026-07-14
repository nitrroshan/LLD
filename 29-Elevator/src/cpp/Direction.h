#pragma once

enum class Direction { Up, Down, Idle };

inline const char* to_string(Direction d) {
    switch (d) {
        case Direction::Up:   return "UP";
        case Direction::Down: return "DOWN";
        case Direction::Idle: return "IDLE";
    }
    return "?";
}
