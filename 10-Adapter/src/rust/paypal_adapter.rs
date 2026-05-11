use crate::payment_processor::PaymentProcessor;
use crate::paypal_api::PayPalApi;

pub struct PayPalAdapter {
    paypal: PayPalApi,
}

impl PayPalAdapter {
    pub fn new(paypal: PayPalApi) -> Self {
        PayPalAdapter { paypal }
    }
}

impl PaymentProcessor for PayPalAdapter {
    fn process_payment(&self, amount: f64, currency: &str) -> bool {
        let response = self.paypal.send_payment(amount as f32, currency);
        response.status_code == 0
    }

    fn refund(&self, transaction_id: &str) -> bool {
        let response = self.paypal.reverse_payment(transaction_id);
        response.status_code == 0
    }
}
