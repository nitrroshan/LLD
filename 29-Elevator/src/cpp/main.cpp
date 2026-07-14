#include <iostream>
#include <vector>
#include "Elevator.h"
#include "FloorDisplay.h"
#include "HallRequest.h"
#include "CarRequest.h"
#include "NearestElevatorStrategy.h"
#include "ElevatorController.h"

int main() {
    std::cout << "=== Elevator System Demo (C++) ===\n\n";

    // Two elevators; E1 at floor 0, E2 at floor 5.
    Elevator e1("E1", 0);
    Elevator e2("E2", 5);

    // Each has a floor display observing its movement.
    FloorDisplay display1;
    FloorDisplay display2;
    e1.register_observer(&display1);
    e2.register_observer(&display2);

    std::vector<Elevator*> elevators = {&e1, &e2};
    NearestElevatorStrategy nearest;
    ElevatorController controller(elevators, &nearest);

    std::cout << "Submitting hall calls:\n";
    controller.submit(HallRequest(3, Direction::Up));   // nearest to 3: E2 vs E1
    controller.submit(HallRequest(1, Direction::Up));   // nearest to 1: E1

    std::cout << "\nRunning simulation:\n";
    controller.run(12);

    // A passenger inside E1 presses a floor button (car request).
    std::cout << "\nCar request inside E1 to floor 6:\n";
    CarRequest(6).execute_on(e1);
    controller.run(12);

    std::cout << "\nScheduling is pluggable — the same controller could use\n";
    std::cout << "LeastBusyStrategy instead, with no change to the elevators.\n";

    return 0;
}
