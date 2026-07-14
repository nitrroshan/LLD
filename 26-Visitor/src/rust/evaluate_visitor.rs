use crate::visitor::Visitor;
use crate::number_expr::NumberExpr;
use crate::addition::Addition;
use crate::multiplication::Multiplication;

/// Concrete Visitor — computes the numeric value of the expression.
pub struct EvaluateVisitor {
    pub result: f64,
}

impl EvaluateVisitor {
    pub fn new() -> Self {
        EvaluateVisitor { result: 0.0 }
    }
}

impl Visitor for EvaluateVisitor {
    fn visit_number(&mut self, number: &NumberExpr) {
        self.result = number.value();
    }

    fn visit_addition(&mut self, addition: &Addition) {
        addition.left().accept(self);
        let left = self.result;
        addition.right().accept(self);
        let right = self.result;
        self.result = left + right;
    }

    fn visit_multiplication(&mut self, multiplication: &Multiplication) {
        multiplication.left().accept(self);
        let left = self.result;
        multiplication.right().accept(self);
        let right = self.result;
        self.result = left * right;
    }
}
