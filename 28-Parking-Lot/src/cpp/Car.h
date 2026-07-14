#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    explicit Car(std::string plate) : Vehicle(std::move(plate)) {}
    VehicleType type() const override { return VehicleType::Car; }
};
