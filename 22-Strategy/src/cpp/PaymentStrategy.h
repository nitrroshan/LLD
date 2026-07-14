#pragma once

// Strategy — common interface for interchangeable payment algorithms.
class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(double amount) = 0;
};
