#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "PaymentStrategy.h"

// Concrete Strategy — pay by card.
class CardPaymentStrategy : public PaymentStrategy {
    std::string card_number_;

public:
    explicit CardPaymentStrategy(std::string card_number) : card_number_(std::move(card_number)) {}

    bool pay(int amount_cents) override {
        std::string masked = "****" + card_number_.substr(card_number_.size() - 4);
        std::cout << "    Card " << masked << " charged $"
                  << std::fixed << std::setprecision(2) << amount_cents / 100.0 << "\n";
        return true;
    }
};
