package chapter39;

/**
 * Demo — registers drivers, matches the nearest available one through a caching
 * location proxy, prices with normal/surge strategies, runs a trip through its
 * state machine, and notifies rider and driver.
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== Ride-Sharing Demo (Java) ===\n");

        // Location service behind a caching proxy (Proxy pattern).
        LocationService location = new CachingLocationServiceProxy(new RealLocationService());
        RideSharingService service = new RideSharingService(location);

        // Drivers via the factory.
        service.registerDriver(new Driver("D1", "Alice",
                VehicleFactory.create(VehicleType.SEDAN, "KA-01"), new Location(2, 2)));
        service.registerDriver(new Driver("D2", "Bob",
                VehicleFactory.create(VehicleType.SEDAN, "KA-02"), new Location(8, 9)));
        service.registerDriver(new Driver("D3", "Carol",
                VehicleFactory.create(VehicleType.SUV, "KA-03"), new Location(1, 1)));

        Rider rider = new Rider("R1", "Dave", new Location(0, 0));
        Location pickup = new Location(0, 0);
        Location drop = new Location(3, 4);   // distance 5 from pickup

        RideMatchingStrategy nearest = new NearestDriverMatchingStrategy();

        // 1) Normal-priced ride: nearest SEDAN is Alice (2,2).
        System.out.println("Scenario 1: request a SEDAN (normal pricing)");
        Trip trip = service.requestRide(rider, pickup, drop, VehicleType.SEDAN,
                nearest, new NormalPricingStrategy());
        service.startTrip(trip);
        service.endTrip(trip);
        trip.driver().addRating(5);

        // 2) Surge-priced ride: Alice is free again; note the cache hit for pickup->drop.
        System.out.println("\nScenario 2: request a SEDAN (surge x1.8) — watch the proxy cache");
        Rider rider2 = new Rider("R2", "Erin", new Location(0, 0));
        Trip surge = service.requestRide(rider2, pickup, drop, VehicleType.SEDAN,
                nearest, new SurgePricingStrategy(1.8));
        service.startTrip(surge);
        service.endTrip(surge);

        // 3) Cancellation before the trip starts.
        System.out.println("\nScenario 3: request then cancel");
        Trip toCancel = service.requestRide(new Rider("R3", "Frank", new Location(0, 0)),
                pickup, drop, VehicleType.SUV, nearest, new NormalPricingStrategy());
        toCancel.cancel();
        System.out.println("  Trip state: " + toCancel.stateName());

        // 4) Illegal action: cannot start a cancelled trip.
        System.out.println("\nScenario 4: illegal action on a cancelled trip");
        toCancel.start();
    }
}
