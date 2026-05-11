/// Third-party Stripe API — different interface, amounts in cents.
pub struct StripeApi;

pub struct StripeResult {
    pub success: bool,
    pub id: String,
}

impl StripeApi {
    pub fn create_charge(&self, cents: i32, currency: &str, token: &str) -> StripeResult {
        println!("  [Stripe] Charging {} cents ({}) token={}", cents, currency, token);
        StripeResult {
            success: true,
            id: format!("ch_{}", std::time::SystemTime::now()
                .duration_since(std::time::UNIX_EPOCH).unwrap().as_nanos()),
        }
    }

    pub fn create_refund(&self, charge_id: &str) -> StripeResult {
        println!("  [Stripe] Refunding charge {}", charge_id);
        StripeResult {
            success: true,
            id: format!("re_{}", std::time::SystemTime::now()
                .duration_since(std::time::UNIX_EPOCH).unwrap().as_nanos()),
        }
    }
}
