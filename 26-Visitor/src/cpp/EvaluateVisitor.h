#pragma once
#include "Visitor.h"
#include "NumberExpr.h"
#include "Addition.h"
#include "Multiplication.h"

// Concrete Visitor — computes the numeric value of the expression.
class EvaluateVisitor : public Visitor {
    double result_ = 0;

public:
    double result() const { return result_; }

    void visit(NumberExpr& number) override {
        result_ = number.value();
    }

    void visit(Addition& addition) override {
        addition.left().accept(*this);
        double left = result_;
        addition.right().accept(*this);
        double right = result_;
        result_ = left + right;
    }

    void visit(Multiplication& multiplication) override {
        multiplication.left().accept(*this);
        double left = result_;
        multiplication.right().accept(*this);
        double right = result_;
        result_ = left * right;
    }
};
