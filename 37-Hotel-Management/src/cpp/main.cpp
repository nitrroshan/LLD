#include <iostream>
#include <memory>
#include "Hotel.h"
#include "RoomFactory.h"
#include "PricingStrategies.h"
#include "ReservationObservers.h"
#include "Guest.h"

int main() {
    std::cout << "=== Hotel Management Demo (C++) ===\n\n";

    BasePricingStrategy base_pricing;
    Hotel hotel("Grand LLD Hotel", &base_pricing);

    // Factory-built rooms.
    hotel.add_room(RoomFactory::create(RoomType::Single, "101"));
    hotel.add_room(RoomFactory::create(RoomType::Double, "201"));
    hotel.add_room(RoomFactory::create(RoomType::Suite,  "301"));

    // Observers.
    GuestNotifier notifier;
    HousekeepingService housekeeping;
    hotel.add_observer(&notifier);
    hotel.add_observer(&housekeeping);

    Guest alice("G1", "Alice");

    // 1) Full lifecycle: book -> check-in -> check-out (State + Observer).
    std::cout << "Scenario 1: book -> check-in -> check-out\n";
    Reservation* res = hotel.book_room(alice, RoomType::Double, 3);   // base: 150*3 = 450
    if (res) {
        hotel.check_in(*res);
        hotel.check_out(*res);
    }

    // 2) Switch to seasonal pricing and book the suite (Strategy).
    std::cout << "\nScenario 2: seasonal pricing\n";
    SeasonalPricingStrategy peak(1.5);
    hotel.set_pricing(&peak);
    Guest bob("G2", "Bob");
    hotel.book_room(bob, RoomType::Suite, 2);                         // 300*2*1.5 = 900 (left booked)

    // 3) No suite left — the only suite is booked by Bob.
    std::cout << "\nScenario 3: sold-out room type\n";
    Guest carol("G3", "Carol");
    hotel.book_room(carol, RoomType::Suite, 1);

    // 4) Illegal action refused by the state machine.
    std::cout << "\nScenario 4: check out a room nobody is in\n";
    auto singles = hotel.search_available(RoomType::Single);
    singles.front()->check_out();   // Available state refuses it

    return 0;
}
