use crate::number_expr::NumberExpr;
use crate::addition::Addition;
use crate::multiplication::Multiplication;

/// Visitor — one visit method per concrete element type. A new operation is a
/// new implementor; the element types never change.
///
/// Idiomatic note: for a CLOSED set of element types, Rust programmers often
/// use an `enum` + `match` instead of this accept/visit ceremony.
pub trait Visitor {
    fn visit_number(&mut self, number: &NumberExpr);
    fn visit_addition(&mut self, addition: &Addition);
    fn visit_multiplication(&mut self, multiplication: &Multiplication);
}
