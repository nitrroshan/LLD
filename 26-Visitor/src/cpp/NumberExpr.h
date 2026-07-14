#pragma once
#include "Expression.h"
#include "Visitor.h"

// Concrete Element — a literal number.
class NumberExpr : public Expression {
    double value_;

public:
    explicit NumberExpr(double value) : value_(value) {}

    double value() const { return value_; }

    void accept(Visitor& visitor) override {
        visitor.visit(*this);   // double dispatch: picks visit(NumberExpr&)
    }
};
