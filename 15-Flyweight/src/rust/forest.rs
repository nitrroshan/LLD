use crate::tree::Tree;
use crate::tree_factory::TreeFactory;

/// Client — plants many trees. Each `Tree` holds only its position;
/// the heavy shared data lives once per `TreeType` in the factory.
pub struct Forest {
    trees: Vec<Tree>,
    factory: TreeFactory,
}

impl Forest {
    pub fn new() -> Self {
        Forest { trees: Vec::new(), factory: TreeFactory::new() }
    }

    pub fn plant_tree(&mut self, x: i32, y: i32, name: &str, color: &str, texture: &str) {
        let kind = self.factory.get_tree_type(name, color, texture);
        self.trees.push(Tree::new(x, y, kind));
    }

    pub fn draw(&self) {
        for tree in &self.trees {
            tree.draw();
        }
    }

    pub fn tree_count(&self) -> usize {
        self.trees.len()
    }

    pub fn distinct_type_count(&self) -> usize {
        self.factory.distinct_type_count()
    }
}
