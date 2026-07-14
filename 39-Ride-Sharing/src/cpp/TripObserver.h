#pragma once
#include <string>

class Trip;

// Observer — reacts to trip status changes without the trip knowing the listener.
class TripObserver {
public:
    virtual ~TripObserver() = default;
    virtual void on_status_changed(Trip& trip, const std::string& status) = 0;
};
