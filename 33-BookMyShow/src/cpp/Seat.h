#pragma once
#include <string>
#include "SeatType.h"

// A physical seat in a screen's layout (per-show state lives in Show).
class Seat {
    std::string id_;
    int row_;
    int number_;
    SeatType type_;

public:
    Seat(std::string id, int row, int number, SeatType type)
        : id_(std::move(id)), row_(row), number_(number), type_(type) {}

    const std::string& id() const { return id_; }
    int row() const { return row_; }
    int number() const { return number_; }
    SeatType type() const { return type_; }
};
