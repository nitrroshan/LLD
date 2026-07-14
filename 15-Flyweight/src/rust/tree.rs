use std::rc::Rc;

use crate::tree_type::TreeType;

/// Context — stores extrinsic (unique) state (x, y) plus a shared `Rc`
/// handle to the flyweight. Many trees share one `TreeType`.
pub struct Tree {
    x: i32,
    y: i32,
    kind: Rc<TreeType>,
}

impl Tree {
    pub fn new(x: i32, y: i32, kind: Rc<TreeType>) -> Self {
        Tree { x, y, kind }
    }

    pub fn draw(&self) {
        self.kind.draw(self.x, self.y);
    }
}
