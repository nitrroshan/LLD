#pragma once
#include <string>

enum class BookingStatus { Confirmed, Failed };

inline const char* to_string(BookingStatus s) {
    return s == BookingStatus::Confirmed ? "CONFIRMED" : "FAILED";
}

// The record of a booking attempt.
struct Booking {
    std::string id;
    BookingStatus status;
    double amount;
};
