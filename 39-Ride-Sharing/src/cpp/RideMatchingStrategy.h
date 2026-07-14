#pragma once
#include <vector>
#include "Driver.h"
#include "Location.h"
#include "LocationService.h"

// Strategy — chooses a driver from the available candidates for a pickup.
class RideMatchingStrategy {
public:
    virtual ~RideMatchingStrategy() = default;
    virtual Driver* select_driver(const std::vector<Driver*>& candidates,
                                  const Location& pickup, LocationService& loc) const = 0;
};

// Matching — pick the closest available driver to the pickup.
class NearestDriverMatchingStrategy : public RideMatchingStrategy {
public:
    Driver* select_driver(const std::vector<Driver*>& candidates,
                          const Location& pickup, LocationService& loc) const override {
        Driver* best = nullptr;
        double best_distance = 1e18;
        for (Driver* d : candidates) {
            double distance = loc.get_distance(pickup, d->location());
            if (distance < best_distance) {
                best_distance = distance;
                best = d;
            }
        }
        return best;
    }
};
