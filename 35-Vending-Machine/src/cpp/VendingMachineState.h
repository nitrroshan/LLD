#pragma once
#include <string>
#include "Coin.h"

class PaymentStrategy;

// State — the four user actions behave differently per state. A default no-op
// dispense() lets only DispensingState perform the release.
class VendingMachineState {
public:
    virtual ~VendingMachineState() = default;
    virtual void select_product(const std::string& code) = 0;
    virtual void insert_coin(Coin coin) = 0;
    virtual void pay_with(PaymentStrategy& strategy) = 0;
    virtual void cancel() = 0;
    virtual void dispense() {}
    virtual const char* name() const = 0;
};
