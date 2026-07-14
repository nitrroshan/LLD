#pragma once
#include <string>
#include "Guest.h"
#include "Room.h"

enum class ReservationStatus { Confirmed, CheckedIn, Completed, Cancelled };

// A booking record: who, which room, how many nights, the amount, and status.
class Reservation {
    std::string id_;
    Guest& guest_;
    Room& room_;
    int nights_;
    double amount_;
    ReservationStatus status_ = ReservationStatus::Confirmed;

public:
    Reservation(std::string id, Guest& guest, Room& room, int nights, double amount)
        : id_(std::move(id)), guest_(guest), room_(room), nights_(nights), amount_(amount) {}

    const std::string& id() const { return id_; }
    Guest& guest() const { return guest_; }
    Room& room() const { return room_; }
    int nights() const { return nights_; }
    double amount() const { return amount_; }
    ReservationStatus status() const { return status_; }
    void set_status(ReservationStatus status) { status_ = status; }
};
