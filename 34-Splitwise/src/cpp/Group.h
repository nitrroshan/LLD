#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "User.h"
#include "Expense.h"
#include "SplitStrategy.h"
#include "BalanceSheet.h"
#include "BalanceObserver.h"
#include "Settlement.h"

// Mediator — members interact only through the group. Adding an expense routes
// here: compute splits (Strategy), update the shared BalanceSheet, notify
// observers. Members never settle with each other directly.
class Group {
    std::string name_;
    std::vector<User*> members_;
    std::vector<Expense> expenses_;
    BalanceSheet balance_sheet_;
    std::vector<BalanceObserver*> observers_;

    void notify_balance(User* debtor, User* creditor, double amount) {
        for (auto* o : observers_) o->on_balance_updated(debtor, creditor, amount);
    }

public:
    explicit Group(std::string name) : name_(std::move(name)) {}

    void add_member(User* user) { members_.push_back(user); }
    void add_observer(BalanceObserver* observer) { observers_.push_back(observer); }

    void add_expense(const std::string& description, double amount, User* paid_by,
                     const std::vector<User*>& participants, const SplitStrategy& strategy) {
        std::vector<Split> splits = strategy.calculate_splits(amount, participants);
        expenses_.push_back(Expense{description, amount, paid_by, splits});
        std::cout << "  " << paid_by->name() << " paid $" << std::fixed << std::setprecision(2)
                  << amount << " for '" << description << "'\n";

        for (const Split& split : splits) {
            if (split.user != paid_by) {
                balance_sheet_.add_debt(split.user, paid_by, split.amount);
                notify_balance(split.user, paid_by, split.amount);
            }
        }
    }

    void show_balances() const {
        std::cout << "  Balances for group '" << name_ << "':\n";
        balance_sheet_.show();
    }

    std::vector<Settlement> simplify() const {
        return balance_sheet_.simplify(members_);
    }
};
