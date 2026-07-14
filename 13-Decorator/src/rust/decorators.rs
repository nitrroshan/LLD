use crate::coffee::Coffee;

pub struct MilkDecorator {
    wrapped: Box<dyn Coffee>,
}

impl MilkDecorator {
    pub fn new(wrapped: Box<dyn Coffee>) -> Self {
        MilkDecorator { wrapped }
    }
}

impl Coffee for MilkDecorator {
    fn get_description(&self) -> String {
        format!("{}, Milk", self.wrapped.get_description())
    }
    fn get_cost(&self) -> f64 {
        self.wrapped.get_cost() + 0.50
    }
}

pub struct WhipDecorator {
    wrapped: Box<dyn Coffee>,
}

impl WhipDecorator {
    pub fn new(wrapped: Box<dyn Coffee>) -> Self {
        WhipDecorator { wrapped }
    }
}

impl Coffee for WhipDecorator {
    fn get_description(&self) -> String {
        format!("{}, Whip", self.wrapped.get_description())
    }
    fn get_cost(&self) -> f64 {
        self.wrapped.get_cost() + 0.70
    }
}

pub struct CaramelDecorator {
    wrapped: Box<dyn Coffee>,
}

impl CaramelDecorator {
    pub fn new(wrapped: Box<dyn Coffee>) -> Self {
        CaramelDecorator { wrapped }
    }
}

impl Coffee for CaramelDecorator {
    fn get_description(&self) -> String {
        format!("{}, Caramel", self.wrapped.get_description())
    }
    fn get_cost(&self) -> f64 {
        self.wrapped.get_cost() + 0.60
    }
}
