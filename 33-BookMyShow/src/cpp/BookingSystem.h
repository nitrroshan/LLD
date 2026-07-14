#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "Show.h"
#include "User.h"
#include "Payment.h"
#include "Booking.h"
#include "PricingStrategy.h"
#include "SeatAvailabilityListener.h"

// Singleton coordinator. Owns the show registry and runs the double-booking-safe
// workflow: lock -> price -> pay -> confirm (or release), then notify observers.
class BookingSystem {
    std::unordered_map<std::string, Show*> shows_;   // non-owning; shows owned externally
    std::vector<SeatAvailabilityListener*> listeners_;
    int booking_counter_ = 0;

    BookingSystem() = default;

    std::string next_id() { return "B" + std::to_string(++booking_counter_); }

    void notify_booked(Show& show, const std::vector<std::string>& seat_ids, const User& user) {
        for (auto* l : listeners_) l->on_seats_booked(show, seat_ids, user);
    }
    void notify_sold_out(Show& show) {
        for (auto* l : listeners_) l->on_sold_out(show);
    }

public:
    BookingSystem(const BookingSystem&) = delete;
    BookingSystem& operator=(const BookingSystem&) = delete;

    static BookingSystem& instance() {
        static BookingSystem system;
        return system;
    }

    void add_show(Show* show) { shows_[show->id()] = show; }
    void add_listener(SeatAvailabilityListener* listener) { listeners_.push_back(listener); }

    Booking book(const std::string& show_id, const std::vector<std::string>& seat_ids,
                 const User& user, const PricingStrategy& pricing) {
        auto it = shows_.find(show_id);
        if (it == shows_.end()) {
            std::cout << "  Booking failed: unknown show\n";
            return Booking{next_id(), BookingStatus::Failed, 0};
        }
        Show& show = *it->second;

        // 1) Lock (critical section) — reject if any requested seat is taken.
        if (!show.lock_seats(seat_ids, user.id())) {
            std::cout << "  " << user.name() << ": requested seats not available\n";
            return Booking{next_id(), BookingStatus::Failed, 0};
        }

        // 2) Price via the chosen strategy.
        double amount = 0;
        for (const auto& seat_id : seat_ids) {
            Seat* seat = show.screen()->get_seat(seat_id);
            amount += pricing.calculate_price(*seat, show);
        }

        // 3) Pay, then confirm or release.
        std::cout << "  " << user.name() << " booking (" << show.movie()->title() << "):\n";
        Payment payment(amount);
        if (payment.process()) {
            show.confirm_seats(seat_ids, user.id());
            notify_booked(show, seat_ids, user);
            if (show.is_sold_out()) {
                notify_sold_out(show);
            }
            return Booking{next_id(), BookingStatus::Confirmed, amount};
        } else {
            show.release_seats(seat_ids, user.id());
            return Booking{next_id(), BookingStatus::Failed, 0};
        }
    }
};
