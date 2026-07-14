#pragma once
#include <memory>
#include "Expression.h"
#include "Visitor.h"

// Concrete Element — multiplication of two sub-expressions (owns its children).
class Multiplication : public Expression {
    std::unique_ptr<Expression> left_;
    std::unique_ptr<Expression> right_;

public:
    Multiplication(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left_(std::move(left)), right_(std::move(right)) {}

    Expression& left() const { return *left_; }
    Expression& right() const { return *right_; }

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};
