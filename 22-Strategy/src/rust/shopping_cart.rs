use crate::payment_strategy::PaymentStrategy;

/// Context — holds a payment strategy and delegates checkout to it. The
/// strategy (a boxed trait object) can be swapped at runtime.
pub struct ShoppingCart {
    total: f64,
    strategy: Option<Box<dyn PaymentStrategy>>,
}

impl ShoppingCart {
    pub fn new() -> Self {
        ShoppingCart { total: 0.0, strategy: None }
    }

    pub fn add_item(&mut self, name: &str, price: f64) {
        self.total += price;
        println!("  + {} (${:.2})", name, price);
    }

    pub fn set_payment_strategy(&mut self, strategy: Box<dyn PaymentStrategy>) {
        self.strategy = Some(strategy);
    }

    pub fn checkout(&mut self) {
        match &self.strategy {
            Some(strategy) => {
                strategy.pay(self.total);
                self.total = 0.0;
            }
            None => println!("  No payment method selected!"),
        }
    }
}
