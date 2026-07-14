#pragma once
#include <memory>
#include "Expression.h"
#include "Context.h"

// Non-terminal Expression — logical OR of two sub-expressions.
class OrExpression : public Expression {
    std::unique_ptr<Expression> left_;
    std::unique_ptr<Expression> right_;

public:
    OrExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left_(std::move(left)), right_(std::move(right)) {}

    bool interpret(const Context& context) const override {
        return left_->interpret(context) || right_->interpret(context);
    }
};
