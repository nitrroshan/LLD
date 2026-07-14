#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include "PaymentType.h"

// A way to pay for an order. Concrete methods are built by the PaymentFactory.
class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    virtual bool pay(double amount) = 0;
};

class CardPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        std::cout << "    Paid " << std::fixed << std::setprecision(1) << amount << " by Card\n";
        return true;
    }
};

class UpiPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        std::cout << "    Paid " << std::fixed << std::setprecision(1) << amount << " by UPI\n";
        return true;
    }
};

class WalletPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        std::cout << "    Paid " << std::fixed << std::setprecision(1) << amount << " by Wallet\n";
        return true;
    }
};

class CodPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        std::cout << "    Cash on delivery: " << std::fixed << std::setprecision(1) << amount << " due\n";
        return true;
    }
};

// Factory — builds a PaymentMethod from a PaymentType. Adding a method is one
// new class plus one case here; the ordering flow never changes.
class PaymentFactory {
public:
    static std::unique_ptr<PaymentMethod> create(PaymentType type) {
        switch (type) {
            case PaymentType::Card:   return std::make_unique<CardPayment>();
            case PaymentType::Upi:    return std::make_unique<UpiPayment>();
            case PaymentType::Wallet: return std::make_unique<WalletPayment>();
            case PaymentType::Cod:    return std::make_unique<CodPayment>();
        }
        return nullptr;
    }
};
