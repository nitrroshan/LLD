#pragma once
#include <string>
#include "Location.h"

// A rider requesting trips.
class Rider {
    std::string id_;
    std::string name_;
    Location location_;
public:
    Rider(std::string id, std::string name, Location location)
        : id_(std::move(id)), name_(std::move(name)), location_(location) {}
    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }
    const Location& location() const { return location_; }
};
