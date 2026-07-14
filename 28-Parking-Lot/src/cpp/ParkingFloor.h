#pragma once
#include <vector>
#include <memory>
#include "ParkingSpot.h"
#include "Vehicle.h"

// A floor owns its spots and searches them for a fit.
class ParkingFloor {
    int number_;
    std::vector<std::unique_ptr<ParkingSpot>> spots_;

public:
    explicit ParkingFloor(int number) : number_(number) {}

    int number() const { return number_; }

    void add_spot(std::unique_ptr<ParkingSpot> spot) {
        spots_.push_back(std::move(spot));
    }

    // First-fit: return the first free spot that can hold the vehicle.
    ParkingSpot* find_available_spot(const Vehicle& vehicle) {
        for (auto& spot : spots_) {
            if (spot->can_fit(vehicle)) {
                return spot.get();
            }
        }
        return nullptr;
    }

    int available_count() const {
        int count = 0;
        for (const auto& spot : spots_) {
            if (spot->is_available()) {
                count++;
            }
        }
        return count;
    }

    int total_spots() const { return static_cast<int>(spots_.size()); }
};
