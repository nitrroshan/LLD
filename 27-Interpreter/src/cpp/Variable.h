#pragma once
#include <string>
#include "Expression.h"
#include "Context.h"

// Terminal Expression — a variable that looks up its value in the context.
class Variable : public Expression {
    std::string name_;

public:
    explicit Variable(std::string name) : name_(std::move(name)) {}

    bool interpret(const Context& context) const override {
        return context.get(name_);
    }
};
