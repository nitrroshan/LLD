#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle {
public:
    explicit Motorcycle(std::string plate) : Vehicle(std::move(plate)) {}
    VehicleType type() const override { return VehicleType::Motorcycle; }
};
