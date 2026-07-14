#pragma once
#include <iostream>
#include <string>
#include "TripObserver.h"
#include "Trip.h"

// Observer — notifies the rider of status changes.
class RiderNotifier : public TripObserver {
public:
    void on_status_changed(Trip& trip, const std::string& status) override {
        std::cout << "    [Rider " << trip.rider()->name() << "] trip is now " << status << "\n";
    }
};

// Observer — notifies the assigned driver of status changes.
class DriverNotifier : public TripObserver {
public:
    void on_status_changed(Trip& trip, const std::string& status) override {
        std::string driver = trip.driver() ? trip.driver()->name() : "(unassigned)";
        std::cout << "    [Driver " << driver << "] trip is now " << status << "\n";
    }
};
