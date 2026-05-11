#include "Car.h"
#include "Motorcycle.h"
#include "ElectricCar.h"
#include <vector>
#include <memory>

/**
 * TODO: Complete the main function to demonstrate polymorphism.
 *
 * 1. Create a vector of unique_ptr<Vehicle> with at least:
 *    - One Car
 *    - One Motorcycle
 *    - One ElectricCar
 *
 * 2. Loop through and call displayInfo() on each
 *
 * 3. Call accelerate(20) on each and print updated info
 *
 * Expected output:
 *   --- Vehicle Info ---
 *   Car: Toyota | Speed: 120 km/h | Doors: 4
 *   Motorcycle: Harley | Speed: 100 km/h | Sidecar: No
 *   ElectricCar: Tesla | Speed: 150 km/h | Doors: 4 | Battery: 85 kWh
 *
 *   --- After Accelerating ---
 *   Toyota accelerated! New speed: 140 km/h
 *   Harley accelerated! New speed: 120 km/h
 *   Tesla accelerated! New speed: 170 km/h
 *
 * Compile & Run:
 *   cd 01-OOP-Refresher/assignments/easy/src/cpp
 *   g++ -std=c++17 -o main main.cpp
 *   ./main
 */
int main() {
    // TODO: Create vehicles using std::make_unique<>

    // TODO: Print "--- Vehicle Info ---"
    // TODO: Loop and call displayInfo()

    // TODO: Print "\n--- After Accelerating ---"
    // TODO: Loop, call accelerate(20), then displayInfo()

    return 0;
}
