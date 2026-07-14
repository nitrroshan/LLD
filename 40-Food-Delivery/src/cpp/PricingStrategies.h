#pragma once

// Strategy — computes the delivery fee from distance and order subtotal.
class DeliveryPricingStrategy {
public:
    virtual ~DeliveryPricingStrategy() = default;
    virtual double calculate_fee(double distance_km, double subtotal) const = 0;
};

// Distance-based delivery fee: a flat base plus a per-km charge.
class DistanceBasedPricingStrategy : public DeliveryPricingStrategy {
    double base_;
    double per_km_;
public:
    DistanceBasedPricingStrategy(double base, double per_km) : base_(base), per_km_(per_km) {}
    double calculate_fee(double distance_km, double) const override {
        return base_ + per_km_ * distance_km;
    }
};

// Free delivery above a subtotal threshold, otherwise a flat fee.
class FreeAboveThresholdPricingStrategy : public DeliveryPricingStrategy {
    double threshold_;
    double flat_fee_;
public:
    FreeAboveThresholdPricingStrategy(double threshold, double flat_fee)
        : threshold_(threshold), flat_fee_(flat_fee) {}
    double calculate_fee(double, double subtotal) const override {
        return subtotal >= threshold_ ? 0.0 : flat_fee_;
    }
};
