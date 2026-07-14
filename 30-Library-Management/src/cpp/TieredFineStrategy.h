#pragma once
#include "FineStrategy.h"

// Concrete Strategy — cheap for the first week, then escalates.
class TieredFineStrategy : public FineStrategy {
    double low_rate_;
    double high_rate_;
    int threshold_;

public:
    TieredFineStrategy(double low_rate, double high_rate, int threshold)
        : low_rate_(low_rate), high_rate_(high_rate), threshold_(threshold) {}

    double calculate_fine(int overdue_days) const override {
        if (overdue_days <= threshold_) {
            return overdue_days * low_rate_;
        }
        return threshold_ * low_rate_ + (overdue_days - threshold_) * high_rate_;
    }
};
