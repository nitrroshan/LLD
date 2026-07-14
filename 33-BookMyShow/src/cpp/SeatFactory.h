#pragma once
#include <string>
#include "Seat.h"

// Factory Method — builds seats with a consistent id scheme.
class SeatFactory {
public:
    static Seat create_seat(int row, int number, SeatType type) {
        std::string id = "R" + std::to_string(row) + "C" + std::to_string(number);
        return Seat(id, row, number, type);
    }
};
