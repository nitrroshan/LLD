use crate::expression::Expression;
use crate::context::Context;

/// Non-terminal Expression — logical NOT of one sub-expression.
pub struct NotExpression {
    expression: Box<dyn Expression>,
}

impl NotExpression {
    pub fn new(expression: Box<dyn Expression>) -> Self {
        NotExpression { expression }
    }
}

impl Expression for NotExpression {
    fn interpret(&self, context: &Context) -> bool {
        !self.expression.interpret(context)
    }
}
