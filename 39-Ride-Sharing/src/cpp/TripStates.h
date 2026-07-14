#pragma once
#include <iostream>
#include "TripState.h"
#include "Trip.h"
#include "Driver.h"

// Concrete states as stateless singletons. Declarations first, then out-of-line
// inline definitions so a state can reference its siblings' singletons.

class RequestedState : public TripState {
public:
    static RequestedState& instance() { static RequestedState s; return s; }
    void assign_driver(Trip& trip, Driver* driver) override;
    void start(Trip& trip) override;
    void end(Trip& trip) override;
    void cancel(Trip& trip) override;
    const char* name() const override { return "REQUESTED"; }
};

class DriverAssignedState : public TripState {
public:
    static DriverAssignedState& instance() { static DriverAssignedState s; return s; }
    void assign_driver(Trip& trip, Driver* driver) override;
    void start(Trip& trip) override;
    void end(Trip& trip) override;
    void cancel(Trip& trip) override;
    const char* name() const override { return "DRIVER_ASSIGNED"; }
};

class InProgressState : public TripState {
public:
    static InProgressState& instance() { static InProgressState s; return s; }
    void assign_driver(Trip& trip, Driver* driver) override;
    void start(Trip& trip) override;
    void end(Trip& trip) override;
    void cancel(Trip& trip) override;
    const char* name() const override { return "IN_PROGRESS"; }
};

class CompletedState : public TripState {
public:
    static CompletedState& instance() { static CompletedState s; return s; }
    void assign_driver(Trip&, Driver*) override { rejected(); }
    void start(Trip&) override { rejected(); }
    void end(Trip&) override { rejected(); }
    void cancel(Trip&) override { rejected(); }
    const char* name() const override { return "COMPLETED"; }
private:
    static void rejected() { std::cout << "    Trip is already completed\n"; }
};

class CancelledState : public TripState {
public:
    static CancelledState& instance() { static CancelledState s; return s; }
    void assign_driver(Trip&, Driver*) override { rejected(); }
    void start(Trip&) override { rejected(); }
    void end(Trip&) override { rejected(); }
    void cancel(Trip&) override { rejected(); }
    const char* name() const override { return "CANCELLED"; }
private:
    static void rejected() { std::cout << "    Trip is already cancelled\n"; }
};

// --- Requested transitions ---
inline void RequestedState::assign_driver(Trip& trip, Driver* driver) {
    trip.set_driver(driver);
    trip.set_state(&DriverAssignedState::instance());
    trip.notify_observers("DRIVER_ASSIGNED");
}
inline void RequestedState::start(Trip&) { std::cout << "    No driver assigned yet\n"; }
inline void RequestedState::end(Trip&) { std::cout << "    Trip hasn't started\n"; }
inline void RequestedState::cancel(Trip& trip) {
    trip.set_state(&CancelledState::instance());
    trip.notify_observers("CANCELLED");
}

// --- DriverAssigned transitions ---
inline void DriverAssignedState::assign_driver(Trip&, Driver*) { std::cout << "    Driver already assigned\n"; }
inline void DriverAssignedState::start(Trip& trip) {
    trip.set_state(&InProgressState::instance());
    trip.notify_observers("IN_PROGRESS");
}
inline void DriverAssignedState::end(Trip&) { std::cout << "    Trip hasn't started\n"; }
inline void DriverAssignedState::cancel(Trip& trip) {
    trip.set_state(&CancelledState::instance());
    trip.notify_observers("CANCELLED");
}

// --- InProgress transitions ---
inline void InProgressState::assign_driver(Trip&, Driver*) { std::cout << "    Trip already in progress\n"; }
inline void InProgressState::start(Trip&) { std::cout << "    Trip already started\n"; }
inline void InProgressState::end(Trip& trip) {
    trip.set_state(&CompletedState::instance());
    trip.notify_observers("COMPLETED");
}
inline void InProgressState::cancel(Trip&) { std::cout << "    Cannot cancel a trip in progress\n"; }
