use crate::context::Context;

/// AbstractExpression — every grammar rule implements interpret(context).
///
/// Idiomatic note: in Rust a grammar is often an `enum` with one variant per
/// rule, evaluated by a single `interpret` method using `match`. We use the
/// trait-object form here to parallel the other languages.
pub trait Expression {
    fn interpret(&self, context: &Context) -> bool;
}
