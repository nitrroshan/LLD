/// OCP — Open/Closed Principle
/// New discount types = new structs implementing the trait

pub trait DiscountStrategy {
    fn calculate(&self, amount: f64) -> f64;
}

pub struct RegularDiscount;
impl DiscountStrategy for RegularDiscount {
    fn calculate(&self, amount: f64) -> f64 { amount * 0.05 }
}

pub struct PremiumDiscount;
impl DiscountStrategy for PremiumDiscount {
    fn calculate(&self, amount: f64) -> f64 { amount * 0.10 }
}

pub struct VIPDiscount;
impl DiscountStrategy for VIPDiscount {
    fn calculate(&self, amount: f64) -> f64 { amount * 0.20 }
}

pub struct EmployeeDiscount;
impl DiscountStrategy for EmployeeDiscount {
    fn calculate(&self, amount: f64) -> f64 { amount * 0.30 }
}

pub fn calculate_discount(strategy: &dyn DiscountStrategy, amount: f64) -> f64 {
    strategy.calculate(amount)
}
