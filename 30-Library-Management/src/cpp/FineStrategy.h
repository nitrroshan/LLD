#pragma once

// Strategy — computes the fine for an overdue return.
class FineStrategy {
public:
    virtual ~FineStrategy() = default;
    virtual double calculate_fine(int overdue_days) const = 0;
};
