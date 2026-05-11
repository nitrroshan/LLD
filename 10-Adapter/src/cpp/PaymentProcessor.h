#pragma once
#include <string>

// Target interface — what our client code expects
class PaymentProcessor {
public:
    virtual ~PaymentProcessor() = default;
    virtual bool process_payment(double amount, const std::string& currency) = 0;
    virtual bool refund(const std::string& transaction_id) = 0;
};
