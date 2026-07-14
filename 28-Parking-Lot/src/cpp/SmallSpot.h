#pragma once
#include "ParkingSpot.h"

class SmallSpot : public ParkingSpot {
public:
    explicit SmallSpot(std::string id) : ParkingSpot(std::move(id), SpotType::Small) {}
};
