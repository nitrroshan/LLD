#pragma once
#include "ParkingSpot.h"

class LargeSpot : public ParkingSpot {
public:
    explicit LargeSpot(std::string id) : ParkingSpot(std::move(id), SpotType::Large) {}
};
