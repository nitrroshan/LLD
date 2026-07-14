mod expression;
mod context;
mod variable;
mod constant;
mod and_expression;
mod or_expression;
mod not_expression;

use expression::Expression;
use context::Context;
use variable::Variable;
use and_expression::AndExpression;
use or_expression::OrExpression;
use not_expression::NotExpression;

fn evaluate(rule: &dyn Expression, a: bool, b: bool, c: bool) {
    let mut context = Context::new();
    context.set("A", a);
    context.set("B", b);
    context.set("C", c);
    println!("  A={}, B={}, C={} -> {}", a, b, c, rule.interpret(&context));
}

fn main() {
    println!("=== Interpreter Pattern Demo (Rust) ===\n");

    // Build the rule tree for: (A OR B) AND (NOT C)
    let rule = AndExpression::new(
        Box::new(OrExpression::new(
            Box::new(Variable::new("A")),
            Box::new(Variable::new("B")),
        )),
        Box::new(NotExpression::new(Box::new(Variable::new("C")))),
    );

    println!("Rule: (A OR B) AND (NOT C)\n");

    evaluate(&rule, true, false, false);
    evaluate(&rule, false, false, false);
    evaluate(&rule, true, true, true);
}
