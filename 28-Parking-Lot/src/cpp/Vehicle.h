#pragma once
#include <string>
#include "VehicleType.h"

// Abstract vehicle. Concrete subclasses declare their type (and thus size).
class Vehicle {
    std::string license_plate_;

public:
    explicit Vehicle(std::string license_plate)
        : license_plate_(std::move(license_plate)) {}
    virtual ~Vehicle() = default;

    const std::string& license_plate() const { return license_plate_; }
    virtual VehicleType type() const = 0;
};
