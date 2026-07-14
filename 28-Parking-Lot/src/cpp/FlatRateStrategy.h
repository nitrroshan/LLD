#pragma once
#include "PricingStrategy.h"

// Concrete Strategy — one flat fee regardless of duration.
class FlatRateStrategy : public PricingStrategy {
    double flat_fee_;

public:
    explicit FlatRateStrategy(double flat_fee) : flat_fee_(flat_fee) {}

    double calculate_price(const Ticket&, long) const override {
        return flat_fee_;
    }
};
