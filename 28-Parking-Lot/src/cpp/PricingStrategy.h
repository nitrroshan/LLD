#pragma once
#include "Ticket.h"

// Strategy — computes the parking fee. Swapped at exit.
class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculate_price(const Ticket& ticket, long exit_time) const = 0;
};
