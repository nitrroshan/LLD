#pragma once
#include <memory>
#include "Expression.h"
#include "Context.h"

// Non-terminal Expression — logical NOT of one sub-expression.
class NotExpression : public Expression {
    std::unique_ptr<Expression> expression_;

public:
    explicit NotExpression(std::unique_ptr<Expression> expression)
        : expression_(std::move(expression)) {}

    bool interpret(const Context& context) const override {
        return !expression_->interpret(context);
    }
};
