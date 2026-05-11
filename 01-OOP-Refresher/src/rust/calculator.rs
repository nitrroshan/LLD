// Rust does NOT support function overloading.
// Use different method names or generics instead.

pub struct Calculator;

impl Calculator {
    pub fn add_i32(&self, a: i32, b: i32) -> i32 {
        a + b
    }

    pub fn add_f64(&self, a: f64, b: f64) -> f64 {
        a + b
    }

    pub fn add_three(&self, a: i32, b: i32, c: i32) -> i32 {
        a + b + c
    }
}
