#include <iostream>
#include <memory>
#include "Expression.h"
#include "Context.h"
#include "Variable.h"
#include "AndExpression.h"
#include "OrExpression.h"
#include "NotExpression.h"

static std::unique_ptr<Expression> build_rule() {
    // (A OR B) AND (NOT C)
    return std::make_unique<AndExpression>(
        std::make_unique<OrExpression>(
            std::make_unique<Variable>("A"),
            std::make_unique<Variable>("B")),
        std::make_unique<NotExpression>(
            std::make_unique<Variable>("C")));
}

static void evaluate(const Expression& rule, bool a, bool b, bool c) {
    Context context;
    context.set("A", a);
    context.set("B", b);
    context.set("C", c);
    std::cout << "  A=" << a << ", B=" << b << ", C=" << c
              << " -> " << rule.interpret(context) << "\n";
}

int main() {
    std::cout << "=== Interpreter Pattern Demo (C++) ===\n\n";
    std::cout << "Rule: (A OR B) AND (NOT C)\n\n";

    auto rule = build_rule();

    evaluate(*rule, true, false, false);
    evaluate(*rule, false, false, false);
    evaluate(*rule, true, true, true);

    return 0;
}
