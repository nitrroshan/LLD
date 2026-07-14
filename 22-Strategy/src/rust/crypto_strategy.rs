use crate::payment_strategy::PaymentStrategy;

/// Concrete Strategy — pays with cryptocurrency.
pub struct CryptoStrategy {
    wallet: String,
}

impl CryptoStrategy {
    pub fn new(wallet: &str) -> Self {
        CryptoStrategy { wallet: wallet.to_string() }
    }
}

impl PaymentStrategy for CryptoStrategy {
    fn pay(&self, amount: f64) {
        println!("  Paid ${:.2} in crypto from wallet {}", amount, self.wallet);
    }
}
