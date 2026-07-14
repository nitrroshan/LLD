#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "Room.h"
#include "RoomType.h"
#include "Guest.h"
#include "Reservation.h"
#include "PricingStrategy.h"
#include "ReservationObserver.h"

// Coordinator — owns the rooms, reservations, observers, and pricing strategy.
// Handles search, booking, check-in, and check-out, and fires events to observers.
class Hotel {
    std::string name_;
    std::vector<std::unique_ptr<Room>> rooms_;
    std::vector<std::unique_ptr<Reservation>> reservations_;
    std::vector<ReservationObserver*> observers_;
    PricingStrategy* pricing_;
    int counter_ = 0;

public:
    Hotel(std::string name, PricingStrategy* pricing)
        : name_(std::move(name)), pricing_(pricing) {}

    void add_room(std::unique_ptr<Room> room) { rooms_.push_back(std::move(room)); }
    void add_observer(ReservationObserver* observer) { observers_.push_back(observer); }
    void set_pricing(PricingStrategy* pricing) { pricing_ = pricing; }

    std::vector<Room*> search_available(RoomType type) {
        std::vector<Room*> result;
        for (auto& room : rooms_) {
            if (room->type() == type && std::string(room->state_name()) == "AVAILABLE") {
                result.push_back(room.get());
            }
        }
        return result;
    }

    Reservation* book_room(Guest& guest, RoomType type, int nights) {
        auto available = search_available(type);
        if (available.empty()) {
            std::cout << "  No " << to_string(type) << " rooms available\n";
            return nullptr;
        }
        Room* room = available.front();
        room->book();                                          // State: Available -> Booked
        double amount = pricing_->calculate_price(type, nights); // Strategy
        std::string id = "R" + std::to_string(++counter_);
        auto reservation = std::make_unique<Reservation>(id, guest, *room, nights, amount);
        Reservation* raw = reservation.get();
        reservations_.push_back(std::move(reservation));
        for (auto* observer : observers_) {                     // Observer
            observer->on_reserved(*raw);
        }
        return raw;
    }

    void check_in(Reservation& reservation) {
        reservation.room().check_in();                          // State: Booked -> Occupied
        reservation.set_status(ReservationStatus::CheckedIn);
    }

    void check_out(Reservation& reservation) {
        reservation.room().check_out();                         // State: Occupied -> Available
        reservation.set_status(ReservationStatus::Completed);
        for (auto* observer : observers_) {                     // Observer
            observer->on_checked_out(reservation);
        }
    }

    const std::string& name() const { return name_; }
};
