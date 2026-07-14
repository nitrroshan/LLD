#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <iomanip>
#include "Driver.h"
#include "Rider.h"
#include "Trip.h"
#include "TripStates.h"
#include "TripObservers.h"
#include "LocationService.h"
#include "RideMatchingStrategy.h"
#include "PricingStrategies.h"
#include "VehicleType.h"
#include "Location.h"

// Coordinator — registers drivers and orchestrates a ride: match a driver
// (Strategy) via the caching LocationService (Proxy), create a Trip (State),
// price it (Strategy), and drive it through start/end while notifying observers.
class RideSharingService {
    std::vector<std::unique_ptr<Driver>> drivers_;
    std::vector<std::unique_ptr<Trip>> trips_;
    LocationService& location_;

public:
    explicit RideSharingService(LocationService& location) : location_(location) {}

    Driver* register_driver(std::unique_ptr<Driver> driver) {
        Driver* raw = driver.get();
        drivers_.push_back(std::move(driver));
        return raw;
    }

    Trip* request_ride(Rider& rider, Location pickup, Location drop, VehicleType type,
                       const RideMatchingStrategy& matching, const PricingStrategy& pricing) {
        std::vector<Driver*> candidates;
        for (auto& d : drivers_)
            if (d->is_available() && d->vehicle().type() == type) candidates.push_back(d.get());
        if (candidates.empty()) {
            std::cout << "  No available " << to_string(type) << " drivers\n";
            return nullptr;
        }

        Driver* driver = matching.select_driver(candidates, pickup, location_);   // Strategy + Proxy
        auto trip = std::make_unique<Trip>(&rider, pickup, drop);
        trip->set_state(&RequestedState::instance());
        trip->add_observer(std::make_unique<RiderNotifier>());
        trip->add_observer(std::make_unique<DriverNotifier>());
        Trip* raw = trip.get();
        trips_.push_back(std::move(trip));

        raw->assign_driver(driver);             // State: Requested -> DriverAssigned
        driver->set_available(false);

        double km = location_.get_distance(pickup, drop);   // Proxy (cache hit if seen)
        raw->set_fare(pricing.calculate_fare(km, driver->vehicle()));   // Strategy
        std::cout << "  Matched " << driver->name() << " (" << to_string(driver->vehicle().type())
                  << "), fare = " << std::fixed << std::setprecision(1) << raw->fare() << "\n";
        return raw;
    }

    void start_trip(Trip* trip) { trip->start(); }

    void end_trip(Trip* trip) {
        trip->end();
        if (trip->driver()) trip->driver()->set_available(true);
        std::cout << "  Charged " << std::fixed << std::setprecision(1) << trip->fare()
                  << " to " << trip->rider()->name() << "\n";
    }
};
