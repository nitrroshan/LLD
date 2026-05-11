pub trait PaymentProcessor {
    fn process_payment(&self, amount: f64, currency: &str) -> bool;
    fn refund(&self, transaction_id: &str) -> bool;
}
