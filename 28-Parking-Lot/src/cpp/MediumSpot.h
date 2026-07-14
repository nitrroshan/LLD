#pragma once
#include "ParkingSpot.h"

class MediumSpot : public ParkingSpot {
public:
    explicit MediumSpot(std::string id) : ParkingSpot(std::move(id), SpotType::Medium) {}
};
