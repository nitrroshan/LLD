#pragma once
#include "PricingStrategy.h"

// Concrete Strategy — wraps a base strategy and applies a surge multiplier
// (e.g., weekends). Composition over a base strategy, so surge works on top of
// ANY tier scheme without duplicating prices.
class WeekendSurgePricingStrategy : public PricingStrategy {
    const PricingStrategy* base_;
    double multiplier_;

public:
    WeekendSurgePricingStrategy(const PricingStrategy* base, double multiplier)
        : base_(base), multiplier_(multiplier) {}

    double calculate_price(const Seat& seat, const Show& show) const override {
        return base_->calculate_price(seat, show) * multiplier_;
    }
};
