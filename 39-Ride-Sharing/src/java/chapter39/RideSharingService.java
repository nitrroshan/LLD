package chapter39;

import java.util.ArrayList;
import java.util.List;

/**
 * Coordinator — registers drivers and orchestrates a ride: match a driver
 * (Strategy) via the caching LocationService (Proxy), create a Trip (State),
 * price it (Strategy), and drive it through start/end while notifying observers.
 */
public class RideSharingService {
    private final List<Driver> drivers = new ArrayList<>();
    private final LocationService locationService;

    public RideSharingService(LocationService locationService) {
        this.locationService = locationService;
    }

    public void registerDriver(Driver driver) {
        drivers.add(driver);
    }

    public Trip requestRide(Rider rider, Location pickup, Location drop, VehicleType type,
                            RideMatchingStrategy matching, PricingStrategy pricing) {
        // Candidates: available drivers with the requested vehicle type.
        List<Driver> candidates = new ArrayList<>();
        for (Driver d : drivers) {
            if (d.isAvailable() && d.vehicle().type() == type) candidates.add(d);
        }
        if (candidates.isEmpty()) {
            System.out.println("  No available " + type + " drivers");
            return null;
        }

        Driver driver = matching.selectDriver(candidates, pickup, locationService);   // Strategy + Proxy
        Trip trip = new Trip(rider, pickup, drop);
        trip.addObserver(new RiderNotifier());
        trip.addObserver(new DriverNotifier());

        trip.assignDriver(driver);              // State: Requested -> DriverAssigned
        driver.setAvailable(false);

        double km = locationService.getDistance(pickup, drop);   // Proxy (cache hit if seen)
        trip.setFare(pricing.calculateFare(km, driver.vehicle())); // Strategy
        System.out.printf("  Matched %s (%s), fare = %.1f%n",
                driver.name(), driver.vehicle().type(), trip.fare());
        return trip;
    }

    public void startTrip(Trip trip) {
        trip.start();
    }

    public void endTrip(Trip trip) {
        trip.end();
        if (trip.driver() != null) trip.driver().setAvailable(true);
        System.out.printf("  Charged %.1f to %s%n", trip.fare(), trip.rider().name());
    }
}
