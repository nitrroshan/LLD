/// Component trait — operations that can be decorated.
pub trait Coffee {
    fn get_description(&self) -> String;
    fn get_cost(&self) -> f64;
}
