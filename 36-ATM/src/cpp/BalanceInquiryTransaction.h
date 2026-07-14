#pragma once
#include <string>
#include <iostream>
#include "Transaction.h"
#include "Account.h"

// Command — read the account balance.
class BalanceInquiryTransaction : public Transaction {
    Account& account_;

public:
    explicit BalanceInquiryTransaction(Account& account) : account_(account) {}

    void execute() override {
        std::cout << "  Balance: $" << account_.balance() << "\n";
    }

    std::string description() const override { return "Balance inquiry"; }
};
