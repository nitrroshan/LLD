#pragma once
#include <string>
#include "VehicleType.h"

// A vehicle of a given type with a plate. Built by the VehicleFactory.
class Vehicle {
    VehicleType type_;
    std::string plate_;
public:
    Vehicle(VehicleType type, std::string plate) : type_(type), plate_(std::move(plate)) {}
    VehicleType type() const { return type_; }
    const std::string& plate() const { return plate_; }
    double rate_per_km() const { return ::rate_per_km(type_); }
};
