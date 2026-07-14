#pragma once
#include <string>
#include "Location.h"

// A customer who places orders.
class Customer {
    std::string id_;
    std::string name_;
    Location location_;
public:
    Customer(std::string id, std::string name, Location location)
        : id_(std::move(id)), name_(std::move(name)), location_(location) {}
    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }
    const Location& location() const { return location_; }
};
