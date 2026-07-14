#pragma once
#include "Vehicle.h"

class Truck : public Vehicle {
public:
    explicit Truck(std::string plate) : Vehicle(std::move(plate)) {}
    VehicleType type() const override { return VehicleType::Truck; }
};
