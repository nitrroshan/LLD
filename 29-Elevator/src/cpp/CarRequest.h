#pragma once
#include <string>
#include "Request.h"
#include "Elevator.h"

// Concrete Command — internal car request; applies directly to that car.
class CarRequest : public Request {
    int target_floor_;

public:
    explicit CarRequest(int target_floor) : target_floor_(target_floor) {}

    int floor() const override { return target_floor_; }
    Direction direction() const override { return Direction::Idle; }
    void execute_on(Elevator& elevator) const override { elevator.add_target(target_floor_); }
    std::string describe() const override {
        return "car request to floor " + std::to_string(target_floor_);
    }
};
