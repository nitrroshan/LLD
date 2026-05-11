use std::f64::consts::PI;
use crate::drawable::Drawable;

pub struct Circle {
    pub radius: f64,
}

impl Drawable for Circle {
    fn draw(&self) {
        println!("Drawing Circle with radius {}", self.radius);
    }

    fn area(&self) -> f64 {
        PI * self.radius * self.radius
    }
}
