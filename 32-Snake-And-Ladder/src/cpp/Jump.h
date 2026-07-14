#pragma once
#include "JumpType.h"

// A relocation on the board from a start cell to an end cell. Snakes and
// ladders are both jumps — they differ only in direction and label.
class Jump {
    int start_;
    int end_;

public:
    Jump(int start, int end) : start_(start), end_(end) {}
    virtual ~Jump() = default;

    int start() const { return start_; }
    int end() const { return end_; }
    virtual JumpType type() const = 0;
};
