use crate::expression::Expression;
use crate::visitor::Visitor;

/// Concrete Element — multiplication of two sub-expressions (owns its children).
pub struct Multiplication {
    left: Box<dyn Expression>,
    right: Box<dyn Expression>,
}

impl Multiplication {
    pub fn new(left: Box<dyn Expression>, right: Box<dyn Expression>) -> Self {
        Multiplication { left, right }
    }

    pub fn left(&self) -> &dyn Expression {
        self.left.as_ref()
    }

    pub fn right(&self) -> &dyn Expression {
        self.right.as_ref()
    }
}

impl Expression for Multiplication {
    fn accept(&self, visitor: &mut dyn Visitor) {
        visitor.visit_multiplication(self);
    }
}
