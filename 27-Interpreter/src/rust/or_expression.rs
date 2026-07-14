use crate::expression::Expression;
use crate::context::Context;

/// Non-terminal Expression — logical OR of two sub-expressions.
pub struct OrExpression {
    left: Box<dyn Expression>,
    right: Box<dyn Expression>,
}

impl OrExpression {
    pub fn new(left: Box<dyn Expression>, right: Box<dyn Expression>) -> Self {
        OrExpression { left, right }
    }
}

impl Expression for OrExpression {
    fn interpret(&self, context: &Context) -> bool {
        self.left.interpret(context) || self.right.interpret(context)
    }
}
