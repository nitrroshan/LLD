#pragma once
#include <string>
#include "Request.h"
#include "Elevator.h"

// Concrete Command — external hall call; the controller picks which elevator.
class HallRequest : public Request {
    int floor_;
    Direction direction_;

public:
    HallRequest(int floor, Direction direction) : floor_(floor), direction_(direction) {}

    int floor() const override { return floor_; }
    Direction direction() const override { return direction_; }
    void execute_on(Elevator& elevator) const override { elevator.add_target(floor_); }
    std::string describe() const override {
        return "hall call at floor " + std::to_string(floor_) + " going " + to_string(direction_);
    }
};
