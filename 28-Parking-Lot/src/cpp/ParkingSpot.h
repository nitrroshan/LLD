#pragma once
#include <string>
#include <stdexcept>
#include "SpotType.h"
#include "Vehicle.h"

// Abstract parking spot. Holds a non-owning pointer to the parked vehicle.
// Fit logic is size-based: free AND spot size >= vehicle size.
class ParkingSpot {
    std::string id_;
    SpotType type_;
    Vehicle* parked_ = nullptr;

public:
    ParkingSpot(std::string id, SpotType type)
        : id_(std::move(id)), type_(type) {}
    virtual ~ParkingSpot() = default;

    const std::string& id() const { return id_; }
    SpotType type() const { return type_; }
    bool is_available() const { return parked_ == nullptr; }

    bool can_fit(const Vehicle& vehicle) const {
        return is_available() && size_of(type_) >= size_of(vehicle.type());
    }

    void park(Vehicle& vehicle) {
        if (!can_fit(vehicle)) {
            throw std::runtime_error("Spot cannot fit vehicle");
        }
        parked_ = &vehicle;
    }

    void vacate() { parked_ = nullptr; }
    Vehicle* parked_vehicle() const { return parked_; }
};
