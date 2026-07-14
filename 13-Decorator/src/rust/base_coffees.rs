use crate::coffee::Coffee;

pub struct Espresso;

impl Coffee for Espresso {
    fn get_description(&self) -> String { "Espresso".to_string() }
    fn get_cost(&self) -> f64 { 2.00 }
}

pub struct Latte;

impl Coffee for Latte {
    fn get_description(&self) -> String { "Latte".to_string() }
    fn get_cost(&self) -> f64 { 3.00 }
}
