#pragma once

// Strategy — an instant payment method that tenders the full amount at once.
class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual bool pay(int amount_cents) = 0;
};
