#pragma once
#include <memory>
#include <string>
#include "Vehicle.h"
#include "VehicleType.h"

// Factory — builds a vehicle for a given type (which carries its per-km rate).
class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> create(VehicleType type, const std::string& plate) {
        return std::make_unique<Vehicle>(type, plate);
    }
};
