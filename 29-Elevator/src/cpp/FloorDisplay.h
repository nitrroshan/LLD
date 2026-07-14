#pragma once
#include <iostream>
#include "ElevatorObserver.h"
#include "Elevator.h"

// Concrete Observer — a display that shows an elevator's live position.
class FloorDisplay : public ElevatorObserver {
public:
    void update(Elevator& elevator) override {
        std::cout << "    [Display " << elevator.id() << "] floor " << elevator.current_floor()
                  << ", " << to_string(elevator.status()) << " " << to_string(elevator.direction()) << "\n";
    }
};
