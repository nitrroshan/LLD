use std::collections::HashMap;
use crate::shapes::Prototype;

pub struct ShapeRegistry {
    prototypes: HashMap<String, Box<dyn Prototype>>,
}

impl ShapeRegistry {
    pub fn new() -> Self {
        ShapeRegistry { prototypes: HashMap::new() }
    }

    pub fn register(&mut self, key: &str, shape: Box<dyn Prototype>) {
        self.prototypes.insert(key.to_string(), shape);
    }

    pub fn get(&self, key: &str) -> Box<dyn Prototype> {
        let prototype = self.prototypes.get(key)
            .unwrap_or_else(|| panic!("Unknown prototype: {}", key));
        prototype.clone_shape()  // return a CLONE, not the original
    }

    pub fn contains(&self, key: &str) -> bool {
        self.prototypes.contains_key(key)
    }

    pub fn size(&self) -> usize {
        self.prototypes.len()
    }
}
