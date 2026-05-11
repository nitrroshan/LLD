/// SRP — Single Responsibility Principle
/// Each struct has ONE job

pub struct Invoice {
    pub product: String,
    pub quantity: u32,
    pub price_per_unit: f64,
}

impl Invoice {
    pub fn new(product: &str, quantity: u32, price_per_unit: f64) -> Self {
        Invoice { product: product.to_string(), quantity, price_per_unit }
    }
    pub fn total(&self) -> f64 { self.quantity as f64 * self.price_per_unit }
}

pub struct InvoicePrinter;
impl InvoicePrinter {
    pub fn print(inv: &Invoice) {
        println!("Invoice: {} x{} = ${:.2}", inv.product, inv.quantity, inv.total());
    }
}

pub struct InvoiceRepository;
impl InvoiceRepository {
    pub fn save(inv: &Invoice) {
        println!("[DB] Saving invoice for {}", inv.product);
    }
}
