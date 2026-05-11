pub trait Drawable {
    fn draw(&self);
    fn area(&self) -> f64;
}
