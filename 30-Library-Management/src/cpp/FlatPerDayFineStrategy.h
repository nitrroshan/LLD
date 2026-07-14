#pragma once
#include "FineStrategy.h"

// Concrete Strategy — a flat charge per overdue day.
class FlatPerDayFineStrategy : public FineStrategy {
    double rate_per_day_;

public:
    explicit FlatPerDayFineStrategy(double rate_per_day) : rate_per_day_(rate_per_day) {}

    double calculate_fine(int overdue_days) const override {
        return overdue_days * rate_per_day_;
    }
};
