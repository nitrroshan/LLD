#include <iostream>
#include <memory>
#include "Expression.h"
#include "NumberExpr.h"
#include "Addition.h"
#include "Multiplication.h"
#include "EvaluateVisitor.h"
#include "PrintVisitor.h"

int main() {
    std::cout << "=== Visitor Pattern Demo (C++) ===\n\n";

    // Build the expression tree: (3 + 4) * 5
    auto expression = std::make_unique<Multiplication>(
        std::make_unique<Addition>(
            std::make_unique<NumberExpr>(3),
            std::make_unique<NumberExpr>(4)),
        std::make_unique<NumberExpr>(5));

    // Operation 1: print — a visitor
    PrintVisitor printer;
    expression->accept(printer);
    std::cout << "Expression: " << printer.result() << "\n";

    // Operation 2: evaluate — another visitor, same elements
    EvaluateVisitor evaluator;
    expression->accept(evaluator);
    std::cout << "Value:      " << evaluator.result() << "\n";

    std::cout << "\nTwo operations, zero changes to the element classes \u2014\n";
    std::cout << "each visitor added a new operation on its own.\n";

    return 0;
}
