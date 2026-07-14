use crate::payment_strategy::PaymentStrategy;

/// Concrete Strategy — pays with a credit card.
pub struct CreditCardStrategy {
    card_number: String,
}

impl CreditCardStrategy {
    pub fn new(card_number: &str) -> Self {
        CreditCardStrategy { card_number: card_number.to_string() }
    }
}

impl PaymentStrategy for CreditCardStrategy {
    fn pay(&self, amount: f64) {
        let masked = format!("****{}", &self.card_number[self.card_number.len() - 4..]);
        println!("  Paid ${:.2} with credit card {}", amount, masked);
    }
}
