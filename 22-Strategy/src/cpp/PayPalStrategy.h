#pragma once
#include <string>
#include <iostream>
#include "PaymentStrategy.h"

// Concrete Strategy — pays via PayPal.
class PayPalStrategy : public PaymentStrategy {
    std::string email_;

public:
    explicit PayPalStrategy(std::string email) : email_(std::move(email)) {}

    void pay(double amount) override {
        std::cout << "  Paid $" << amount << " via PayPal account " << email_ << "\n";
    }
};
