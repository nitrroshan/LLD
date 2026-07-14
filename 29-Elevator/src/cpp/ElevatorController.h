#pragma once
#include <vector>
#include <iostream>
#include "Elevator.h"
#include "Request.h"
#include "SchedulingStrategy.h"

// Coordinates elevators: assigns hall calls via the strategy and drives ticks.
class ElevatorController {
    std::vector<Elevator*> elevators_;   // non-owning; owned by main
    const SchedulingStrategy* strategy_;

public:
    ElevatorController(std::vector<Elevator*> elevators, const SchedulingStrategy* strategy)
        : elevators_(std::move(elevators)), strategy_(strategy) {}

    void set_strategy(const SchedulingStrategy* strategy) { strategy_ = strategy; }

    void submit(const Request& request) {
        Elevator* elevator = strategy_->select(elevators_, request);
        std::cout << "  Dispatch: " << request.describe()
                  << " -> elevator " << elevator->id() << "\n";
        request.execute_on(*elevator);
    }

    void step() {
        for (Elevator* elevator : elevators_) {
            elevator->step();
        }
    }

    bool all_idle() const {
        for (Elevator* elevator : elevators_) {
            if (!elevator->is_idle()) {
                return false;
            }
        }
        return true;
    }

    void run(int max_ticks) {
        for (int tick = 1; tick <= max_ticks && !all_idle(); tick++) {
            std::cout << "-- tick " << tick << " --\n";
            step();
        }
    }
};
