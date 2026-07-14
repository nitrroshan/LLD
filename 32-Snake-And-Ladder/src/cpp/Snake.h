#pragma once
#include "Jump.h"

// A snake: from a higher cell (head) down to a lower one (tail).
class Snake : public Jump {
public:
    Snake(int head, int tail) : Jump(head, tail) {}
    JumpType type() const override { return JumpType::Snake; }
};
