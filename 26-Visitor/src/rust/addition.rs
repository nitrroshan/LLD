use crate::expression::Expression;
use crate::visitor::Visitor;

/// Concrete Element — addition of two sub-expressions (owns its children).
pub struct Addition {
    left: Box<dyn Expression>,
    right: Box<dyn Expression>,
}

impl Addition {
    pub fn new(left: Box<dyn Expression>, right: Box<dyn Expression>) -> Self {
        Addition { left, right }
    }

    pub fn left(&self) -> &dyn Expression {
        self.left.as_ref()
    }

    pub fn right(&self) -> &dyn Expression {
        self.right.as_ref()
    }
}

impl Expression for Addition {
    fn accept(&self, visitor: &mut dyn Visitor) {
        visitor.visit_addition(self);
    }
}
