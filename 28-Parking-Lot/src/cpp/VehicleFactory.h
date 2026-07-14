#pragma once
#include <memory>
#include <string>
#include <stdexcept>
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Car.h"
#include "Truck.h"

// Factory Method — creates a Vehicle from a VehicleType token.
class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> create(VehicleType type, const std::string& plate) {
        switch (type) {
            case VehicleType::Motorcycle: return std::make_unique<Motorcycle>(plate);
            case VehicleType::Car:        return std::make_unique<Car>(plate);
            case VehicleType::Truck:      return std::make_unique<Truck>(plate);
        }
        throw std::invalid_argument("Unknown vehicle type");
    }
};
