use std::collections::HashMap;
use std::rc::Rc;

use crate::tree_type::TreeType;

/// Flyweight Factory — creates and caches shared `Rc<TreeType>` flyweights.
/// The same intrinsic combination always returns a clone of the SAME `Rc`
/// (a refcount bump, not a data copy).
pub struct TreeFactory {
    cache: HashMap<String, Rc<TreeType>>,
}

impl TreeFactory {
    pub fn new() -> Self {
        TreeFactory { cache: HashMap::new() }
    }

    pub fn get_tree_type(&mut self, name: &str, color: &str, texture: &str) -> Rc<TreeType> {
        let key = format!("{}-{}-{}", name, color, texture);
        if let Some(t) = self.cache.get(&key) {
            return Rc::clone(t);
        }
        println!("  [Factory] Creating new TreeType: {}", key);
        let t = Rc::new(TreeType::new(name.to_string(), color.to_string(), texture.to_string()));
        self.cache.insert(key, Rc::clone(&t));
        t
    }

    pub fn distinct_type_count(&self) -> usize {
        self.cache.len()
    }
}
