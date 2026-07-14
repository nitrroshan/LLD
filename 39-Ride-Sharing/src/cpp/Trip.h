#pragma once
#include <vector>
#include <memory>
#include <string>
#include "TripState.h"
#include "TripObserver.h"
#include "Rider.h"
#include "Driver.h"
#include "Location.h"

// Context — a trip. Holds the rider, driver, pickup/drop, fare, current State,
// and observers. All lifecycle actions delegate to the current state. The
// initial state is set by the service (which knows the concrete states).
class Trip {
    Rider* rider_;
    Driver* driver_ = nullptr;
    Location pickup_, drop_;
    double fare_ = 0;
    TripState* state_ = nullptr;                          // shared state singleton
    std::vector<std::unique_ptr<TripObserver>> observers_;

public:
    Trip(Rider* rider, Location pickup, Location drop)
        : rider_(rider), pickup_(pickup), drop_(drop) {}

    void add_observer(std::unique_ptr<TripObserver> o) { observers_.push_back(std::move(o)); }
    void notify_observers(const std::string& status) {
        for (auto& o : observers_) o->on_status_changed(*this, status);
    }

    // Lifecycle actions — delegate to the current state.
    void assign_driver(Driver* d) { state_->assign_driver(*this, d); }
    void start() { state_->start(*this); }
    void end() { state_->end(*this); }
    void cancel() { state_->cancel(*this); }

    void set_state(TripState* s) { state_ = s; }
    const char* state_name() const { return state_->name(); }
    Rider* rider() const { return rider_; }
    Driver* driver() const { return driver_; }
    void set_driver(Driver* d) { driver_ = d; }
    const Location& pickup() const { return pickup_; }
    const Location& drop() const { return drop_; }
    double fare() const { return fare_; }
    void set_fare(double f) { fare_ = f; }
};
