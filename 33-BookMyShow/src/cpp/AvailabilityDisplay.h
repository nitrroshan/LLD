#pragma once
#include <iostream>
#include "SeatAvailabilityListener.h"
#include "Show.h"
#include "User.h"

// Concrete Observer — a display board reacting to bookings and sell-outs.
class AvailabilityDisplay : public SeatAvailabilityListener {
public:
    void on_seats_booked(Show& show, const std::vector<std::string>& seat_ids,
                         const User& user) override {
        std::cout << "    [Display] " << user.name() << " booked ";
        for (std::size_t i = 0; i < seat_ids.size(); ++i) {
            std::cout << seat_ids[i] << (i + 1 < seat_ids.size() ? "," : "");
        }
        std::cout << ". " << show.available_count() << " seats left for '"
                  << show.movie()->title() << "'\n";
    }

    void on_sold_out(Show& show) override {
        std::cout << "    [Display] '" << show.movie()->title() << "' ("
                  << show.start_time() << ") is now SOLD OUT\n";
    }
};
