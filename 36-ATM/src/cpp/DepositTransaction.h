#pragma once
#include <string>
#include <iostream>
#include "Transaction.h"
#include "Account.h"

// Command — deposit cash into the account.
class DepositTransaction : public Transaction {
    Account& account_;
    int amount_;

public:
    DepositTransaction(Account& account, int amount) : account_(account), amount_(amount) {}

    void execute() override {
        account_.credit(amount_);
        std::cout << "  Deposited $" << amount_ << ". New balance: $" << account_.balance() << "\n";
    }

    std::string description() const override { return "Deposit $" + std::to_string(amount_); }
};
