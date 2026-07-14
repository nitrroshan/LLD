#include <iostream>
#include <iomanip>
#include <vector>
#include "Movie.h"
#include "Screen.h"
#include "Theater.h"
#include "SeatFactory.h"
#include "Show.h"
#include "User.h"
#include "SeatTypePricingStrategy.h"
#include "WeekendSurgePricingStrategy.h"
#include "AvailabilityDisplay.h"
#include "BookingSystem.h"

int main() {
    std::cout << "=== BookMyShow Demo (C++) ===\n\n";

    BookingSystem& system = BookingSystem::instance();
    AvailabilityDisplay display;
    system.add_listener(&display);

    // A small screen: row 1 regular, row 2 premium, row 3 recliner (3 seats each).
    Screen screen("SCR1", "Screen 1");
    for (int c = 1; c <= 3; c++) screen.add_seat(SeatFactory::create_seat(1, c, SeatType::Regular));
    for (int c = 1; c <= 3; c++) screen.add_seat(SeatFactory::create_seat(2, c, SeatType::Premium));
    for (int c = 1; c <= 3; c++) screen.add_seat(SeatFactory::create_seat(3, c, SeatType::Recliner));

    Theater theater("TH1", "Downtown Cinema");
    theater.add_screen(&screen);

    Movie movie("M1", "Inception", 148);
    Show show("SH1", &movie, &screen, "Sat 7:00 PM");
    system.add_show(&show);

    // Pricing: weekend surge (x1.5) over base tier prices (Strategy + composition).
    SeatTypePricingStrategy base;
    WeekendSurgePricingStrategy pricing(&base, 1.5);

    User alice("U1", "Alice");
    User bob("U2", "Bob");

    std::cout << "Available seats: " << show.available_count() << "\n\n";

    // Alice books two regular seats.
    Booking b1 = system.book("SH1", {"R1C1", "R1C2"}, alice, pricing);
    std::cout << "  -> " << to_string(b1.status) << " ($"
              << std::fixed << std::setprecision(2) << b1.amount << ")\n\n";

    // Bob tries an already-booked seat + a free one -> rejected (no double-booking).
    Booking b2 = system.book("SH1", {"R1C1", "R1C3"}, bob, pricing);
    std::cout << "  -> " << to_string(b2.status) << "\n\n";

    // Bob books a recliner instead -> confirmed.
    Booking b3 = system.book("SH1", {"R3C1"}, bob, pricing);
    std::cout << "  -> " << to_string(b3.status) << " ($"
              << std::fixed << std::setprecision(2) << b3.amount << ")\n";

    std::cout << "\nOne coordinator, pluggable pricing, factory-built seats,\n";
    std::cout << "observer-notified displays, and lock-safe double-booking prevention.\n";

    return 0;
}
