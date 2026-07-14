use crate::purchase_request::PurchaseRequest;

/// Handler trait. Concrete handlers supply their limit, name, and successor;
/// the default `handle` method provides the shared forwarding logic
/// (this is the "template method" of the chain).
pub trait Approver {
    fn limit(&self) -> f64;
    fn name(&self) -> &str;
    fn next(&self) -> Option<&dyn Approver>;

    fn handle(&self, request: &PurchaseRequest) {
        if request.amount <= self.limit() {
            println!("  {} approved ${:.2} for {}", self.name(), request.amount, request.purpose);
        } else if let Some(next) = self.next() {
            next.handle(request);
        } else {
            println!(
                "  Request for ${:.2} ({}) could not be approved by anyone.",
                request.amount, request.purpose
            );
        }
    }
}
