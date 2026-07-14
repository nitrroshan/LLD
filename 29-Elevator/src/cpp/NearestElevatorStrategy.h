#pragma once
#include <vector>
#include <climits>
#include "SchedulingStrategy.h"
#include "Elevator.h"
#include "Request.h"

// Concrete Strategy — pick the elevator whose current floor is closest.
class NearestElevatorStrategy : public SchedulingStrategy {
public:
    Elevator* select(const std::vector<Elevator*>& elevators,
                     const Request& request) const override {
        Elevator* best = nullptr;
        int best_distance = INT_MAX;
        for (Elevator* elevator : elevators) {
            int diff = elevator->current_floor() - request.floor();
            int distance = diff < 0 ? -diff : diff;
            if (distance < best_distance) {
                best_distance = distance;
                best = elevator;
            }
        }
        return best;
    }
};
