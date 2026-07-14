#pragma once
#include <string>
#include <iostream>
#include "Transaction.h"
#include "Account.h"
#include "CashDispenser.h"

// Command — withdraw cash. Checks balance, dispenses notes, THEN debits, so a
// failed dispense never charges the customer.
class WithdrawTransaction : public Transaction {
    Account& account_;
    CashDispenser& dispenser_;
    int amount_;

public:
    WithdrawTransaction(Account& account, CashDispenser& dispenser, int amount)
        : account_(account), dispenser_(dispenser), amount_(amount) {}

    void execute() override {
        if (amount_ > account_.balance()) {
            std::cout << "  Insufficient account balance (balance $" << account_.balance() << ")\n";
            return;
        }
        if (dispenser_.dispense(amount_)) {
            account_.debit(amount_);
            std::cout << "  Withdrew $" << amount_ << ". New balance: $" << account_.balance() << "\n";
        } else {
            std::cout << "  Withdrawal cancelled\n";
        }
    }

    std::string description() const override { return "Withdraw $" + std::to_string(amount_); }
};
