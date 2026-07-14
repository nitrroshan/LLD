#pragma once
#include <string>

// A player with a name and current board position (0 = start, off the board).
class Player {
    std::string name_;
    int position_ = 0;

public:
    explicit Player(std::string name) : name_(std::move(name)) {}

    const std::string& name() const { return name_; }
    int position() const { return position_; }
    void set_position(int position) { position_ = position; }
};
