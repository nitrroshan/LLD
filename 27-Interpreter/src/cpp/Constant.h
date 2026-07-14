#pragma once
#include "Expression.h"
#include "Context.h"

// Terminal Expression — a literal true/false constant.
class Constant : public Expression {
    bool value_;

public:
    explicit Constant(bool value) : value_(value) {}

    bool interpret(const Context&) const override {
        return value_;
    }
};
