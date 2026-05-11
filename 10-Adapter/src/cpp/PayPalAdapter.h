#pragma once
#include "PaymentProcessor.h"
#include "PayPalApi.h"

class PayPalAdapter : public PaymentProcessor {
private:
    PayPalApi& paypal_;

public:
    PayPalAdapter(PayPalApi& paypal) : paypal_(paypal) {}

    bool process_payment(double amount, const std::string& currency) override {
        auto response = paypal_.send_payment(static_cast<float>(amount), currency);
        return response.status_code == 0;
    }

    bool refund(const std::string& transaction_id) override {
        auto response = paypal_.reverse_payment(transaction_id);
        return response.status_code == 0;
    }
};
