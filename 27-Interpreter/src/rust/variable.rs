use crate::expression::Expression;
use crate::context::Context;

/// Terminal Expression — a variable that looks up its value in the context.
pub struct Variable {
    name: String,
}

impl Variable {
    pub fn new(name: &str) -> Self {
        Variable { name: name.to_string() }
    }
}

impl Expression for Variable {
    fn interpret(&self, context: &Context) -> bool {
        context.get(&self.name)
    }
}
