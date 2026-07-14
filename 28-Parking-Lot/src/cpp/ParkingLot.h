#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>
#include "ParkingFloor.h"
#include "Ticket.h"
#include "PricingStrategy.h"
#include "Payment.h"
#include "Vehicle.h"

// Singleton coordinator (Meyers singleton). Owns floors and active tickets,
// parks/unparks vehicles, and delegates fee calculation to a PricingStrategy.
class ParkingLot {
    std::vector<std::unique_ptr<ParkingFloor>> floors_;
    std::unordered_map<std::string, std::unique_ptr<Ticket>> active_tickets_;
    int ticket_counter_ = 0;

    ParkingLot() = default;

public:
    ParkingLot(const ParkingLot&) = delete;
    ParkingLot& operator=(const ParkingLot&) = delete;

    static ParkingLot& instance() {
        static ParkingLot lot;
        return lot;
    }

    void add_floor(std::unique_ptr<ParkingFloor> floor) {
        floors_.push_back(std::move(floor));
    }

    Ticket* park_vehicle(Vehicle& vehicle, long entry_time) {
        for (auto& floor : floors_) {
            ParkingSpot* spot = floor->find_available_spot(vehicle);
            if (spot) {
                spot->park(vehicle);
                std::string id = "T" + std::to_string(++ticket_counter_);
                auto ticket = std::make_unique<Ticket>(id, &vehicle, spot, entry_time);
                Ticket* raw = ticket.get();
                active_tickets_[id] = std::move(ticket);
                std::cout << "  Parked " << vehicle.license_plate() << " (" << to_string(vehicle.type())
                          << ") at floor " << floor->number() << ", spot " << spot->id()
                          << " -> ticket " << id << "\n";
                return raw;
            }
        }
        std::cout << "  No available spot for " << vehicle.license_plate()
                  << " (" << to_string(vehicle.type()) << ")\n";
        return nullptr;
    }

    Payment unpark_vehicle(Ticket* ticket, long exit_time, const PricingStrategy& strategy) {
        double price = strategy.calculate_price(*ticket, exit_time);
        ticket->spot()->vacate();
        std::cout << "  Unparked " << ticket->vehicle()->license_plate()
                  << " (ticket " << ticket->id() << "), spot " << ticket->spot()->id() << " freed\n";
        active_tickets_.erase(ticket->id());   // ticket is destroyed here
        Payment payment(price);
        payment.process();
        return payment;
    }

    void display_availability() const {
        std::cout << "  Availability:\n";
        for (const auto& floor : floors_) {
            std::cout << "    Floor " << floor->number() << ": "
                      << floor->available_count() << "/" << floor->total_spots() << " free\n";
        }
    }
};
