#pragma once
#include "PricingStrategy.h"
#include "RoomType.h"

// Base pricing — plain nightly rate times nights.
class BasePricingStrategy : public PricingStrategy {
public:
    double calculate_price(RoomType type, int nights) const override {
        return base_price(type) * nights;
    }
};

// Seasonal pricing — applies a peak-season multiplier over the base rate.
class SeasonalPricingStrategy : public PricingStrategy {
    double multiplier_;
public:
    explicit SeasonalPricingStrategy(double multiplier) : multiplier_(multiplier) {}
    double calculate_price(RoomType type, int nights) const override {
        return base_price(type) * nights * multiplier_;
    }
};
