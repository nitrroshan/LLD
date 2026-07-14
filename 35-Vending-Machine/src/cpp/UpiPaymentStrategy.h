#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "PaymentStrategy.h"

// Concrete Strategy — pay by UPI. Adding it required no change to the machine.
class UpiPaymentStrategy : public PaymentStrategy {
    std::string vpa_;

public:
    explicit UpiPaymentStrategy(std::string vpa) : vpa_(std::move(vpa)) {}

    bool pay(int amount_cents) override {
        std::cout << "    UPI " << vpa_ << " paid $"
                  << std::fixed << std::setprecision(2) << amount_cents / 100.0 << "\n";
        return true;
    }
};
