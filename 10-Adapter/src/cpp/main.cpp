#include <iostream>
#include <memory>
#include "StripeAdapter.h"
#include "PayPalAdapter.h"

void process_order(PaymentProcessor& processor, double amount, const std::string& currency) {
    bool success = processor.process_payment(amount, currency);
    std::cout << "  Payment " << (success ? "succeeded" : "failed") << "\n\n";
}

void refund_order(PaymentProcessor& processor, const std::string& transaction_id) {
    bool success = processor.refund(transaction_id);
    std::cout << "  Refund " << (success ? "succeeded" : "failed") << "\n\n";
}

int main() {
    std::cout << "=== Adapter Pattern Demo (C++) ===\n\n";

    StripeApi stripe_api;
    PayPalApi paypal_api;

    StripeAdapter stripe(stripe_api, "sk_test_abc123");
    PayPalAdapter paypal(paypal_api);

    // 1. Process payments through the same interface
    std::cout << "--- Process Payments ---\n";
    process_order(stripe, 49.99, "USD");
    process_order(paypal, 29.99, "EUR");

    // 2. Refunds
    std::cout << "--- Refund Payments ---\n";
    refund_order(stripe, "ch_12345");
    refund_order(paypal, "PAY-67890");

    // 3. Swap implementations
    std::cout << "--- Swap Implementation ---\n";
    PaymentProcessor* processor = &stripe;
    process_order(*processor, 99.99, "USD");

    processor = &paypal;
    process_order(*processor, 99.99, "USD");

    return 0;
}
