#pragma once
#include <vector>
#include <climits>
#include "SchedulingStrategy.h"
#include "Elevator.h"
#include "Request.h"

// Concrete Strategy — pick the elevator with the fewest pending stops.
class LeastBusyStrategy : public SchedulingStrategy {
public:
    Elevator* select(const std::vector<Elevator*>& elevators,
                     const Request&) const override {
        Elevator* best = nullptr;
        int fewest = INT_MAX;
        for (Elevator* elevator : elevators) {
            if (elevator->target_count() < fewest) {
                fewest = elevator->target_count();
                best = elevator;
            }
        }
        return best;
    }
};
