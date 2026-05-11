// Traits are Rust's version of interfaces / abstract classes

pub trait Animal {
    fn name(&self) -> &str;

    fn eat(&self) {
        println!("{} is eating.", self.name());
    }

    fn make_sound(&self); // abstract — must implement
}
