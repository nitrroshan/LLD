mod payment_processor;
mod stripe_api;
mod paypal_api;
mod stripe_adapter;
mod paypal_adapter;

use payment_processor::PaymentProcessor;
use stripe_api::StripeApi;
use paypal_api::PayPalApi;
use stripe_adapter::StripeAdapter;
use paypal_adapter::PayPalAdapter;

fn process_order(processor: &dyn PaymentProcessor, amount: f64, currency: &str) {
    let success = processor.process_payment(amount, currency);
    println!("  Payment {}\n", if success { "succeeded" } else { "failed" });
}

fn refund_order(processor: &dyn PaymentProcessor, transaction_id: &str) {
    let success = processor.refund(transaction_id);
    println!("  Refund {}\n", if success { "succeeded" } else { "failed" });
}

fn main() {
    println!("=== Adapter Pattern Demo (Rust) ===\n");

    let stripe = StripeAdapter::new(StripeApi, "sk_test_abc123");
    let paypal = PayPalAdapter::new(PayPalApi);

    // 1. Process payments through the same trait
    println!("--- Process Payments ---");
    process_order(&stripe, 49.99, "USD");
    process_order(&paypal, 29.99, "EUR");

    // 2. Refunds
    println!("--- Refund Payments ---");
    refund_order(&stripe, "ch_12345");
    refund_order(&paypal, "PAY-67890");

    // 3. Swap implementations via trait object
    println!("--- Swap Implementation ---");
    let processor: &dyn PaymentProcessor = &stripe;
    process_order(processor, 99.99, "USD");

    let processor: &dyn PaymentProcessor = &paypal;
    process_order(processor, 99.99, "USD");
}
