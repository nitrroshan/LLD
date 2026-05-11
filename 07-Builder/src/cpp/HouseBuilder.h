#pragma once
#include "House.h"
#include <stdexcept>

class HouseBuilder {
private:
    int rooms_ = 1;
    int floors_ = 1;
    bool has_garage_ = false;
    bool has_pool_ = false;
    bool has_garden_ = false;
    std::string roof_type_ = "shingle";

public:
    HouseBuilder& rooms(int count) {
        rooms_ = count;
        return *this;
    }

    HouseBuilder& floors(int count) {
        floors_ = count;
        return *this;
    }

    HouseBuilder& garage() {
        has_garage_ = true;
        return *this;
    }

    HouseBuilder& pool() {
        has_pool_ = true;
        return *this;
    }

    HouseBuilder& garden() {
        has_garden_ = true;
        return *this;
    }

    HouseBuilder& roof_type(const std::string& type) {
        roof_type_ = type;
        return *this;
    }

    House build() {
        if (rooms_ < 1) {
            throw std::invalid_argument("House must have at least 1 room");
        }
        if (floors_ < 1) {
            throw std::invalid_argument("House must have at least 1 floor");
        }
        return House(rooms_, floors_, has_garage_, has_pool_, has_garden_, roof_type_);
    }
};
