#pragma once

class Trip;
class Driver;

// State — the trip lifecycle. Each concrete state defines which actions are
// legal and what transition follows; illegal actions are refused. Stateless
// singletons that take the Trip& as a parameter.
class TripState {
public:
    virtual ~TripState() = default;
    virtual void assign_driver(Trip& trip, Driver* driver) = 0;
    virtual void start(Trip& trip) = 0;
    virtual void end(Trip& trip) = 0;
    virtual void cancel(Trip& trip) = 0;
    virtual const char* name() const = 0;
};
