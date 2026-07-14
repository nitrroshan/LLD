#pragma once
#include <iostream>
#include <iomanip>
#include "ReservationObserver.h"
#include "Reservation.h"

// Observer — messages the guest on booking and check-out.
class GuestNotifier : public ReservationObserver {
public:
    void on_reserved(const Reservation& r) override {
        std::cout << "    [SMS to " << r.guest().name() << "] Booking " << r.id()
                  << " confirmed: room " << r.room().number() << " for " << r.nights()
                  << " night(s) ($" << std::fixed << std::setprecision(0) << r.amount() << ")\n";
    }
    void on_checked_out(const Reservation& r) override {
        std::cout << "    [SMS to " << r.guest().name() << "] Thanks for staying with us! ("
                  << r.id() << ")\n";
    }
};

// Observer — schedules cleaning when a guest checks out.
class HousekeepingService : public ReservationObserver {
public:
    void on_reserved(const Reservation&) override {
        // Housekeeping doesn't care about new bookings.
    }
    void on_checked_out(const Reservation& r) override {
        std::cout << "    [Housekeeping] Schedule cleaning for room " << r.room().number() << "\n";
    }
};
