#pragma once
#include <string>
#include <vector>

class Show;
class User;

// Observer — notified as seats are booked or a show sells out.
class SeatAvailabilityListener {
public:
    virtual ~SeatAvailabilityListener() = default;
    virtual void on_seats_booked(Show& show, const std::vector<std::string>& seat_ids,
                                 const User& user) = 0;
    virtual void on_sold_out(Show& show) = 0;
};
