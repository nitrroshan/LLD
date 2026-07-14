#pragma once
#include <iostream>
#include <iomanip>
#include "BalanceObserver.h"

// Concrete Observer — prints a notification on each balance update.
class NotificationObserver : public BalanceObserver {
public:
    void on_balance_updated(User* debtor, User* creditor, double amount) override {
        std::cout << "    [Notify] " << debtor->name() << " owes " << creditor->name()
                  << " $" << std::fixed << std::setprecision(2) << amount << " for this expense\n";
    }
};
