/// The request that travels along the chain of handlers.
pub struct PurchaseRequest {
    pub amount: f64,
    pub purpose: String,
}

impl PurchaseRequest {
    pub fn new(amount: f64, purpose: &str) -> Self {
        PurchaseRequest { amount, purpose: purpose.to_string() }
    }
}
