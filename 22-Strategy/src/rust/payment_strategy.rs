/// Strategy — common trait for interchangeable payment algorithms.
pub trait PaymentStrategy {
    fn pay(&self, amount: f64);
}

/// Blanket impl so any closure `Fn(f64)` is also a PaymentStrategy — this is
/// the lightweight "strategy as a function" form. Named strategy structs
/// don't implement `Fn`, so there is no conflict.
impl<F: Fn(f64)> PaymentStrategy for F {
    fn pay(&self, amount: f64) {
        self(amount);
    }
}
