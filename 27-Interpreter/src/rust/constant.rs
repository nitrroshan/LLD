use crate::expression::Expression;
use crate::context::Context;

/// Terminal Expression — a literal true/false constant.
pub struct Constant {
    value: bool,
}

impl Constant {
    pub fn new(value: bool) -> Self {
        Constant { value }
    }
}

impl Expression for Constant {
    fn interpret(&self, _context: &Context) -> bool {
        self.value
    }
}
