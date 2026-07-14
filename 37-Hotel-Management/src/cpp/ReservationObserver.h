#pragma once

class Reservation;

// Observer — reacts to reservation lifecycle events without the hotel knowing
// the concrete listener.
class ReservationObserver {
public:
    virtual ~ReservationObserver() = default;
    virtual void on_reserved(const Reservation& reservation) = 0;
    virtual void on_checked_out(const Reservation& reservation) = 0;
};
