#pragma once
#include <memory>
#include <string>
#include "Vehicle.h"
#include "Location.h"

// A driver with a vehicle, current location, availability, and a rolling rating.
class Driver {
    std::string id_;
    std::string name_;
    std::unique_ptr<Vehicle> vehicle_;   // the driver owns its vehicle
    Location location_;
    bool available_ = true;
    double rating_ = 5.0;
    int rating_count_ = 1;
public:
    Driver(std::string id, std::string name, std::unique_ptr<Vehicle> vehicle, Location location)
        : id_(std::move(id)), name_(std::move(name)), vehicle_(std::move(vehicle)), location_(location) {}

    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }
    Vehicle& vehicle() const { return *vehicle_; }
    const Location& location() const { return location_; }
    bool is_available() const { return available_; }
    void set_available(bool available) { available_ = available; }
    double rating() const { return rating_; }

    void add_rating(int stars) {
        rating_ = (rating_ * rating_count_ + stars) / (rating_count_ + 1);
        ++rating_count_;
    }
};
