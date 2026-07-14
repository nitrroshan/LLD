#pragma once
#include <string>
#include "Location.h"

// A delivery agent with a location and availability.
class DeliveryAgent {
    std::string id_;
    std::string name_;
    Location location_;
    bool available_ = true;
public:
    DeliveryAgent(std::string id, std::string name, Location location)
        : id_(std::move(id)), name_(std::move(name)), location_(location) {}
    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }
    const Location& location() const { return location_; }
    bool is_available() const { return available_; }
    void set_available(bool available) { available_ = available; }
};
