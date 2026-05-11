#pragma once
#include "PaymentProcessor.h"
#include "StripeApi.h"
#include <cmath>

class StripeAdapter : public PaymentProcessor {
private:
    StripeApi& stripe_;
    std::string api_token_;

public:
    StripeAdapter(StripeApi& stripe, const std::string& api_token)
        : stripe_(stripe), api_token_(api_token) {}

    bool process_payment(double amount, const std::string& currency) override {
        int cents = static_cast<int>(std::round(amount * 100));
        auto result = stripe_.create_charge(cents, currency, api_token_);
        return result.success;
    }

    bool refund(const std::string& transaction_id) override {
        auto result = stripe_.create_refund(transaction_id);
        return result.success;
    }
};
