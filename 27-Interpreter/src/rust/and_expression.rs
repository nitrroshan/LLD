use crate::expression::Expression;
use crate::context::Context;

/// Non-terminal Expression — logical AND of two sub-expressions.
pub struct AndExpression {
    left: Box<dyn Expression>,
    right: Box<dyn Expression>,
}

impl AndExpression {
    pub fn new(left: Box<dyn Expression>, right: Box<dyn Expression>) -> Self {
        AndExpression { left, right }
    }
}

impl Expression for AndExpression {
    fn interpret(&self, context: &Context) -> bool {
        self.left.interpret(context) && self.right.interpret(context)
    }
}
