/// Flyweight — stores ONLY intrinsic (shared) state.
/// Immutable by default in Rust; shared via `Rc` (see the factory).
/// Extrinsic state (x, y) is passed IN via `draw`.
pub struct TreeType {
    name: String,
    color: String,
    texture: String,
}

impl TreeType {
    pub fn new(name: String, color: String, texture: String) -> Self {
        TreeType { name, color, texture }
    }

    pub fn draw(&self, x: i32, y: i32) {
        println!(
            "  Drawing {} ({}, texture={}) at ({}, {})",
            self.name, self.color, self.texture, x, y
        );
    }

    pub fn name(&self) -> &str {
        &self.name
    }
}
