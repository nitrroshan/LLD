#pragma once
#include "Vehicle.h"

// Strategy — computes the fare for a distance and vehicle.
class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculate_fare(double distance_km, const Vehicle& vehicle) const = 0;
};

// Normal pricing — distance times the vehicle's per-km rate.
class NormalPricingStrategy : public PricingStrategy {
public:
    double calculate_fare(double distance_km, const Vehicle& vehicle) const override {
        return distance_km * vehicle.rate_per_km();
    }
};

// Surge pricing — normal fare times a demand multiplier.
class SurgePricingStrategy : public PricingStrategy {
    double multiplier_;
public:
    explicit SurgePricingStrategy(double multiplier) : multiplier_(multiplier) {}
    double calculate_fare(double distance_km, const Vehicle& vehicle) const override {
        return distance_km * vehicle.rate_per_km() * multiplier_;
    }
};
