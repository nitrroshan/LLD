#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "PaymentStrategy.h"

// Context — holds a payment strategy and delegates checkout to it. The
// strategy can be swapped at runtime.
class ShoppingCart {
    double total_ = 0;
    std::unique_ptr<PaymentStrategy> strategy_;

public:
    void add_item(const std::string& name, double price) {
        total_ += price;
        std::cout << "  + " << name << " ($" << price << ")\n";
    }

    void set_payment_strategy(std::unique_ptr<PaymentStrategy> strategy) {
        strategy_ = std::move(strategy);
    }

    void checkout() {
        if (!strategy_) {
            std::cout << "  No payment method selected!\n";
            return;
        }
        strategy_->pay(total_);
        total_ = 0;
    }
};
