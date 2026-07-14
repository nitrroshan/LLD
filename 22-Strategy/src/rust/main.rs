mod payment_strategy;
mod credit_card_strategy;
mod paypal_strategy;
mod crypto_strategy;
mod shopping_cart;

use credit_card_strategy::CreditCardStrategy;
use paypal_strategy::PayPalStrategy;
use crypto_strategy::CryptoStrategy;
use shopping_cart::ShoppingCart;

fn main() {
    println!("=== Strategy Pattern Demo (Rust) ===\n");

    let mut cart = ShoppingCart::new();
    cart.add_item("Keyboard", 49.99);
    cart.add_item("Mouse", 25.50);

    // Choose a strategy at runtime
    println!("\nCheckout with credit card:");
    cart.set_payment_strategy(Box::new(CreditCardStrategy::new("1234567812345678")));
    cart.checkout();

    cart.add_item("Monitor", 199.00);
    println!("\nCheckout with PayPal:");
    cart.set_payment_strategy(Box::new(PayPalStrategy::new("shopper@example.com")));
    cart.checkout();

    cart.add_item("Webcam", 60.00);
    println!("\nCheckout with crypto:");
    cart.set_payment_strategy(Box::new(CryptoStrategy::new("0xABCD...1234")));
    cart.checkout();

    // A closure can also be a strategy, thanks to the blanket impl
    // `impl<F: Fn(f64)> PaymentStrategy for F` in payment_strategy.rs.
    cart.add_item("Cable", 9.99);
    println!("\nCheckout with a closure strategy (Apple Pay):");
    cart.set_payment_strategy(Box::new(|amount: f64| {
        println!("  Paid ${:.2} with Apple Pay", amount);
    }));
    cart.checkout();
}
