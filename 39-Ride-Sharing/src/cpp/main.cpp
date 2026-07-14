#include <iostream>
#include <memory>
#include "RideSharingService.h"
#include "RealLocationService.h"
#include "CachingLocationServiceProxy.h"
#include "VehicleFactory.h"
#include "Rider.h"
#include "Driver.h"
#include "Location.h"

int main() {
    std::cout << "=== Ride-Sharing Demo (C++) ===\n\n";

    // Location service behind a caching proxy (Proxy pattern).
    RealLocationService real;
    CachingLocationServiceProxy location(real);
    RideSharingService service(location);

    // Drivers via the factory.
    service.register_driver(std::make_unique<Driver>("D1", "Alice",
        VehicleFactory::create(VehicleType::Sedan, "KA-01"), Location(2, 2)));
    service.register_driver(std::make_unique<Driver>("D2", "Bob",
        VehicleFactory::create(VehicleType::Sedan, "KA-02"), Location(8, 9)));
    service.register_driver(std::make_unique<Driver>("D3", "Carol",
        VehicleFactory::create(VehicleType::Suv, "KA-03"), Location(1, 1)));

    Rider rider("R1", "Dave", Location(0, 0));
    Location pickup(0, 0);
    Location drop(3, 4);   // distance 5 from pickup

    NearestDriverMatchingStrategy nearest;
    NormalPricingStrategy normal;

    // 1) Normal-priced ride: nearest SEDAN is Alice (2,2).
    std::cout << "Scenario 1: request a SEDAN (normal pricing)\n";
    Trip* trip = service.request_ride(rider, pickup, drop, VehicleType::Sedan, nearest, normal);
    service.start_trip(trip);
    service.end_trip(trip);
    trip->driver()->add_rating(5);

    // 2) Surge-priced ride: Alice is free again; note the cache hit for pickup->drop.
    std::cout << "\nScenario 2: request a SEDAN (surge x1.8) - watch the proxy cache\n";
    Rider rider2("R2", "Erin", Location(0, 0));
    SurgePricingStrategy surge_pricing(1.8);
    Trip* surge = service.request_ride(rider2, pickup, drop, VehicleType::Sedan, nearest, surge_pricing);
    service.start_trip(surge);
    service.end_trip(surge);

    // 3) Cancellation before the trip starts.
    std::cout << "\nScenario 3: request then cancel\n";
    Rider rider3("R3", "Frank", Location(0, 0));
    Trip* to_cancel = service.request_ride(rider3, pickup, drop, VehicleType::Suv, nearest, normal);
    to_cancel->cancel();
    std::cout << "  Trip state: " << to_cancel->state_name() << "\n";

    // 4) Illegal action: cannot start a cancelled trip.
    std::cout << "\nScenario 4: illegal action on a cancelled trip\n";
    to_cancel->start();

    return 0;
}
