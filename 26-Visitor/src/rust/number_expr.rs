use crate::expression::Expression;
use crate::visitor::Visitor;

/// Concrete Element — a literal number.
pub struct NumberExpr {
    value: f64,
}

impl NumberExpr {
    pub fn new(value: f64) -> Self {
        NumberExpr { value }
    }

    pub fn value(&self) -> f64 {
        self.value
    }
}

impl Expression for NumberExpr {
    fn accept(&self, visitor: &mut dyn Visitor) {
        visitor.visit_number(self); // double dispatch
    }
}
