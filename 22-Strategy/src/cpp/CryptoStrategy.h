#pragma once
#include <string>
#include <iostream>
#include "PaymentStrategy.h"

// Concrete Strategy — pays with cryptocurrency.
class CryptoStrategy : public PaymentStrategy {
    std::string wallet_;

public:
    explicit CryptoStrategy(std::string wallet) : wallet_(std::move(wallet)) {}

    void pay(double amount) override {
        std::cout << "  Paid $" << amount << " in crypto from wallet " << wallet_ << "\n";
    }
};
