#pragma once

// Forward declarations — the visitor refers to element types by reference.
class NumberExpr;
class Addition;
class Multiplication;

// Visitor — one (overloaded) visit method per concrete element type.
class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(NumberExpr& number) = 0;
    virtual void visit(Addition& addition) = 0;
    virtual void visit(Multiplication& multiplication) = 0;
};
