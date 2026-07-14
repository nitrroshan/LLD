#pragma once
#include "Seat.h"

class Show;

// Strategy — prices a seat for a show.
class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculate_price(const Seat& seat, const Show& show) const = 0;
};
