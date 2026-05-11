use crate::payment_processor::PaymentProcessor;
use crate::stripe_api::StripeApi;

pub struct StripeAdapter {
    stripe: StripeApi,
    api_token: String,
}

impl StripeAdapter {
    pub fn new(stripe: StripeApi, api_token: &str) -> Self {
        StripeAdapter { stripe, api_token: api_token.to_string() }
    }
}

impl PaymentProcessor for StripeAdapter {
    fn process_payment(&self, amount: f64, currency: &str) -> bool {
        let cents = (amount * 100.0).round() as i32;
        let result = self.stripe.create_charge(cents, currency, &self.api_token);
        result.success
    }

    fn refund(&self, transaction_id: &str) -> bool {
        let result = self.stripe.create_refund(transaction_id);
        result.success
    }
}
