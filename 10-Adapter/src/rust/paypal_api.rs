/// Third-party PayPal API — different interface, amounts as f32.
pub struct PayPalApi;

pub struct PayPalResponse {
    pub status_code: i32,  // 0 = success
    pub payment_id: String,
}

impl PayPalApi {
    pub fn send_payment(&self, amount: f32, currency_code: &str) -> PayPalResponse {
        println!("  [PayPal] Sending {} {}", amount, currency_code);
        PayPalResponse {
            status_code: 0,
            payment_id: format!("PAY-{}", std::time::SystemTime::now()
                .duration_since(std::time::UNIX_EPOCH).unwrap().as_nanos()),
        }
    }

    pub fn reverse_payment(&self, payment_id: &str) -> PayPalResponse {
        println!("  [PayPal] Reversing payment {}", payment_id);
        PayPalResponse {
            status_code: 0,
            payment_id: format!("REV-{}", std::time::SystemTime::now()
                .duration_since(std::time::UNIX_EPOCH).unwrap().as_nanos()),
        }
    }
}
