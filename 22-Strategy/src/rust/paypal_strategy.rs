use crate::payment_strategy::PaymentStrategy;

/// Concrete Strategy — pays via PayPal.
pub struct PayPalStrategy {
    email: String,
}

impl PayPalStrategy {
    pub fn new(email: &str) -> Self {
        PayPalStrategy { email: email.to_string() }
    }
}

impl PaymentStrategy for PayPalStrategy {
    fn pay(&self, amount: f64) {
        println!("  Paid ${:.2} via PayPal account {}", amount, self.email);
    }
}
