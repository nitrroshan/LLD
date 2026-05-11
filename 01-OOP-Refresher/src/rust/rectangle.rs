use crate::drawable::Drawable;

pub struct Rectangle {
    pub width: f64,
    pub height: f64,
}

impl Drawable for Rectangle {
    fn draw(&self) {
        println!("Drawing Rectangle ({} x {})", self.width, self.height);
    }

    fn area(&self) -> f64 {
        self.width * self.height
    }
}
