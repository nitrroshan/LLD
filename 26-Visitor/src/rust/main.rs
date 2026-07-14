mod expression;
mod visitor;
mod number_expr;
mod addition;
mod multiplication;
mod evaluate_visitor;
mod print_visitor;

use expression::Expression;
use number_expr::NumberExpr;
use addition::Addition;
use multiplication::Multiplication;
use evaluate_visitor::EvaluateVisitor;
use print_visitor::PrintVisitor;

fn main() {
    println!("=== Visitor Pattern Demo (Rust) ===\n");

    // Build the expression tree: (3 + 4) * 5
    let expression: Box<dyn Expression> = Box::new(Multiplication::new(
        Box::new(Addition::new(
            Box::new(NumberExpr::new(3.0)),
            Box::new(NumberExpr::new(4.0)),
        )),
        Box::new(NumberExpr::new(5.0)),
    ));

    // Operation 1: print — a visitor
    let mut printer = PrintVisitor::new();
    expression.accept(&mut printer);
    println!("Expression: {}", printer.result);

    // Operation 2: evaluate — another visitor, same elements
    let mut evaluator = EvaluateVisitor::new();
    expression.accept(&mut evaluator);
    println!("Value:      {}", evaluator.result);

    println!("\nTwo operations, zero changes to the element types —");
    println!("each visitor added a new operation on its own.");
}
