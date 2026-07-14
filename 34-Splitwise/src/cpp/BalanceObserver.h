#pragma once
#include "User.h"

// Observer — notified when a balance between two users changes.
class BalanceObserver {
public:
    virtual ~BalanceObserver() = default;
    virtual void on_balance_updated(User* debtor, User* creditor, double amount) = 0;
};
