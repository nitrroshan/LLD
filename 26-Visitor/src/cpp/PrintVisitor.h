#pragma once
#include <string>
#include "Visitor.h"
#include "NumberExpr.h"
#include "Addition.h"
#include "Multiplication.h"

// Concrete Visitor — renders the expression as infix text. Adding this
// operation required NO change to any element class.
class PrintVisitor : public Visitor {
    std::string result_;

public:
    const std::string& result() const { return result_; }

    void visit(NumberExpr& number) override {
        result_ = std::to_string(static_cast<long>(number.value()));
    }

    void visit(Addition& addition) override {
        addition.left().accept(*this);
        std::string left = result_;
        addition.right().accept(*this);
        std::string right = result_;
        result_ = "(" + left + " + " + right + ")";
    }

    void visit(Multiplication& multiplication) override {
        multiplication.left().accept(*this);
        std::string left = result_;
        multiplication.right().accept(*this);
        std::string right = result_;
        result_ = "(" + left + " * " + right + ")";
    }
};
