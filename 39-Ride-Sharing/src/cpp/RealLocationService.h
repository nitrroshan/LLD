#pragma once
#include <iostream>
#include "LocationService.h"

// RealSubject — the "expensive" distance computation (imagine a maps/routing
// call). Prints when it actually computes so the proxy's caching is visible.
class RealLocationService : public LocationService {
public:
    double get_distance(const Location& a, const Location& b) override {
        std::cout << "    [LocationService] computing distance " << a.to_string()
                  << " -> " << b.to_string() << "\n";
        return a.distance_to(b);
    }
};
