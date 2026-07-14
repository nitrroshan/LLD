#pragma once
#include <string>
#include "Location.h"
#include "Menu.h"

// A restaurant with a menu and a location.
class Restaurant {
    std::string id_;
    std::string name_;
    Location location_;
    Menu menu_;
public:
    Restaurant(std::string id, std::string name, Location location, Menu menu)
        : id_(std::move(id)), name_(std::move(name)), location_(location), menu_(std::move(menu)) {}
    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }
    const Location& location() const { return location_; }
    const Menu& menu() const { return menu_; }
};
