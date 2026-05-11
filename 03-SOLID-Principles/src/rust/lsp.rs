/// LSP — Liskov Substitution Principle
/// Separate traits for separate capabilities

pub trait BirdLike {
    fn name(&self) -> &str;
}

pub trait Flyable {
    fn fly(&self);
}

pub struct Sparrow;
impl BirdLike for Sparrow {
    fn name(&self) -> &str { "Sparrow" }
}
impl Flyable for Sparrow {
    fn fly(&self) { println!("Sparrow is flying!"); }
}

pub struct Penguin;
impl BirdLike for Penguin {
    fn name(&self) -> &str { "Penguin" }
}
// Penguin does NOT implement Flyable — compiler enforces LSP
impl Penguin {
    pub fn swim(&self) { println!("Penguin is swimming!"); }
}

pub fn make_fly(f: &dyn Flyable) {
    f.fly();
}
