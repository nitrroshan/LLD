#pragma once
#include <string>
#include "Vehicle.h"
#include "ParkingSpot.h"

// Immutable record of a parked vehicle. Time is in whole hours for the demo.
class Ticket {
    std::string id_;
    Vehicle* vehicle_;
    ParkingSpot* spot_;
    long entry_time_;

public:
    Ticket(std::string id, Vehicle* vehicle, ParkingSpot* spot, long entry_time)
        : id_(std::move(id)), vehicle_(vehicle), spot_(spot), entry_time_(entry_time) {}

    const std::string& id() const { return id_; }
    Vehicle* vehicle() const { return vehicle_; }
    ParkingSpot* spot() const { return spot_; }
    long entry_time() const { return entry_time_; }
};
