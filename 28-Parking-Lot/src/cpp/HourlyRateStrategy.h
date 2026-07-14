#pragma once
#include <algorithm>
#include "PricingStrategy.h"

// Concrete Strategy — charge per hour, scaled by the vehicle's size.
class HourlyRateStrategy : public PricingStrategy {
    double base_rate_per_hour_;

public:
    explicit HourlyRateStrategy(double base_rate_per_hour)
        : base_rate_per_hour_(base_rate_per_hour) {}

    double calculate_price(const Ticket& ticket, long exit_time) const override {
        long hours = std::max(1L, exit_time - ticket.entry_time());
        int size_multiplier = size_of(ticket.vehicle()->type());
        return base_rate_per_hour_ * size_multiplier * static_cast<double>(hours);
    }
};
