#pragma once
#include "PricingStrategy.h"
#include "Seat.h"
#include "SeatType.h"

// Concrete Strategy — base price by seat type (the pricing tiers).
class SeatTypePricingStrategy : public PricingStrategy {
public:
    double calculate_price(const Seat& seat, const Show&) const override {
        switch (seat.type()) {
            case SeatType::Regular:  return 10.0;
            case SeatType::Premium:  return 15.0;
            case SeatType::Recliner: return 25.0;
        }
        return 10.0;
    }
};
