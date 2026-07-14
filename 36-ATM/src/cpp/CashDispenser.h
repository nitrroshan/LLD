#pragma once
#include <memory>
#include <iostream>
#include "DenominationHandler.h"

// Validates a withdrawal amount and drives the denomination chain. Runs a
// non-mutating can_dispense() check first, so it never pays out partial cash.
class CashDispenser {
    std::unique_ptr<DenominationHandler> chain_;

public:
    explicit CashDispenser(std::unique_ptr<DenominationHandler> chain)
        : chain_(std::move(chain)) {}

    bool dispense(int amount) {
        if (amount <= 0 || amount % 10 != 0) {
            std::cout << "    Amount must be a positive multiple of $10\n";
            return false;
        }
        if (amount > chain_->total_cash()) {
            std::cout << "    ATM has insufficient cash\n";
            return false;
        }
        if (!chain_->can_dispense(amount)) {
            std::cout << "    Cannot dispense $" << amount << " with available notes\n";
            return false;
        }
        chain_->dispense(amount);
        return true;
    }
};
