#pragma once
#include "Jump.h"

// A ladder: from a lower cell (bottom) up to a higher one (top).
class Ladder : public Jump {
public:
    Ladder(int bottom, int top) : Jump(bottom, top) {}
    JumpType type() const override { return JumpType::Ladder; }
};
