use crate::visitor::Visitor;
use crate::number_expr::NumberExpr;
use crate::addition::Addition;
use crate::multiplication::Multiplication;

/// Concrete Visitor — renders the expression as infix text. Adding this
/// operation required NO change to any element type.
pub struct PrintVisitor {
    pub result: String,
}

impl PrintVisitor {
    pub fn new() -> Self {
        PrintVisitor { result: String::new() }
    }
}

impl Visitor for PrintVisitor {
    fn visit_number(&mut self, number: &NumberExpr) {
        self.result = format!("{}", number.value());
    }

    fn visit_addition(&mut self, addition: &Addition) {
        addition.left().accept(self);
        let left = self.result.clone();
        addition.right().accept(self);
        let right = self.result.clone();
        self.result = format!("({} + {})", left, right);
    }

    fn visit_multiplication(&mut self, multiplication: &Multiplication) {
        multiplication.left().accept(self);
        let left = self.result.clone();
        multiplication.right().accept(self);
        let right = self.result.clone();
        self.result = format!("({} * {})", left, right);
    }
}
