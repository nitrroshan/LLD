use crate::visitor::Visitor;

/// Element — declares accept. Takes `&mut dyn Visitor` because visitors
/// accumulate their result as they walk the tree.
pub trait Expression {
    fn accept(&self, visitor: &mut dyn Visitor);
}
