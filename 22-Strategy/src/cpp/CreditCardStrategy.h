#pragma once
#include <string>
#include <iostream>
#include "PaymentStrategy.h"

// Concrete Strategy — pays with a credit card.
class CreditCardStrategy : public PaymentStrategy {
    std::string card_number_;

public:
    explicit CreditCardStrategy(std::string card_number)
        : card_number_(std::move(card_number)) {}

    void pay(double amount) override {
        std::string masked = "****" + card_number_.substr(card_number_.size() - 4);
        std::cout << "  Paid $" << amount << " with credit card " << masked << "\n";
    }
};
