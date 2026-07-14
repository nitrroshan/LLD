#include <iostream>
#include <memory>
#include <vector>
#include "ParkingLot.h"
#include "ParkingFloor.h"
#include "SmallSpot.h"
#include "MediumSpot.h"
#include "LargeSpot.h"
#include "VehicleFactory.h"
#include "HourlyRateStrategy.h"
#include "FlatRateStrategy.h"

int main() {
    std::cout << "=== Parking Lot System Demo (C++) ===\n\n";

    ParkingLot& lot = ParkingLot::instance();

    // Floor 1: 1 small, 1 medium, 1 large
    auto floor1 = std::make_unique<ParkingFloor>(1);
    floor1->add_spot(std::make_unique<SmallSpot>("1-S1"));
    floor1->add_spot(std::make_unique<MediumSpot>("1-M1"));
    floor1->add_spot(std::make_unique<LargeSpot>("1-L1"));
    lot.add_floor(std::move(floor1));

    // Floor 2: 1 medium, 1 large
    auto floor2 = std::make_unique<ParkingFloor>(2);
    floor2->add_spot(std::make_unique<MediumSpot>("2-M1"));
    floor2->add_spot(std::make_unique<LargeSpot>("2-L1"));
    lot.add_floor(std::move(floor2));

    lot.display_availability();

    // Vehicles owned by main; created via the factory.
    std::vector<std::unique_ptr<Vehicle>> garage;
    garage.push_back(VehicleFactory::create(VehicleType::Motorcycle, "BIKE-1"));
    garage.push_back(VehicleFactory::create(VehicleType::Car, "CAR-1"));
    garage.push_back(VehicleFactory::create(VehicleType::Truck, "TRUCK-1"));

    std::cout << "\nParking vehicles:\n";
    Ticket* bike_ticket = lot.park_vehicle(*garage[0], 0);
    lot.park_vehicle(*garage[1], 0);   // car stays parked
    Ticket* truck_ticket = lot.park_vehicle(*garage[2], 0);

    lot.display_availability();

    HourlyRateStrategy hourly(2.0);
    FlatRateStrategy flat(40.0);

    std::cout << "\nUnparking with hourly pricing (bike, 3 hours):\n";
    lot.unpark_vehicle(bike_ticket, 3, hourly);

    std::cout << "\nUnparking with flat pricing (truck):\n";
    lot.unpark_vehicle(truck_ticket, 5, flat);

    lot.display_availability();

    std::cout << "\nFilling up, then trying one more truck:\n";
    garage.push_back(VehicleFactory::create(VehicleType::Truck, "TRUCK-2"));
    garage.push_back(VehicleFactory::create(VehicleType::Truck, "TRUCK-3"));
    lot.park_vehicle(*garage[3], 0);   // takes the last large spot
    lot.park_vehicle(*garage[4], 0);   // no large spot left

    return 0;
}
