#pragma once
#include "RoomType.h"

// Strategy — prices a stay given the room type and number of nights.
class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculate_price(RoomType type, int nights) const = 0;
};
