use std::collections::HashMap;

/// Context — holds the boolean value bound to each variable name.
pub struct Context {
    values: HashMap<String, bool>,
}

impl Context {
    pub fn new() -> Self {
        Context { values: HashMap::new() }
    }

    pub fn set(&mut self, name: &str, value: bool) {
        self.values.insert(name.to_string(), value);
    }

    pub fn get(&self, name: &str) -> bool {
        *self.values.get(name).unwrap_or(&false)
    }
}
