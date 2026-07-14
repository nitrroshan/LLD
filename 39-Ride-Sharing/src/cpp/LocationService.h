#pragma once
#include "Location.h"

// Proxy subject — computes the distance between two locations. Real and proxy
// implementations share this interface, so callers can't tell them apart.
class LocationService {
public:
    virtual ~LocationService() = default;
    virtual double get_distance(const Location& a, const Location& b) = 0;
};
