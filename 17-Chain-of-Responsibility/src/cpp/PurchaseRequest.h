#pragma once
#include <string>

// The request that travels along the chain of handlers.
class PurchaseRequest {
    double amount_;
    std::string purpose_;

public:
    PurchaseRequest(double amount, std::string purpose)
        : amount_(amount), purpose_(std::move(purpose)) {}

    double amount() const { return amount_; }
    const std::string& purpose() const { return purpose_; }
};
