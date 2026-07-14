package chapter28;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Parking Lot System Demo ===\n");

        // Singleton lot
        ParkingLot lot = ParkingLot.getInstance();

        // Build floor 1: 1 small, 1 medium, 1 large
        ParkingFloor floor1 = new ParkingFloor(1);
        floor1.addSpot(new SmallSpot("1-S1"));
        floor1.addSpot(new MediumSpot("1-M1"));
        floor1.addSpot(new LargeSpot("1-L1"));
        lot.addFloor(floor1);

        // Build floor 2: 1 medium, 1 large
        ParkingFloor floor2 = new ParkingFloor(2);
        floor2.addSpot(new MediumSpot("2-M1"));
        floor2.addSpot(new LargeSpot("2-L1"));
        lot.addFloor(floor2);

        lot.displayAvailability();

        // Vehicles created via the factory (e.g. from an entrance sensor)
        Vehicle bike = VehicleFactory.create(VehicleType.MOTORCYCLE, "BIKE-1");
        Vehicle car = VehicleFactory.create(VehicleType.CAR, "CAR-1");
        Vehicle truck = VehicleFactory.create(VehicleType.TRUCK, "TRUCK-1");

        System.out.println("\nParking vehicles:");
        Ticket bikeTicket = lot.parkVehicle(bike, 0);    // fits small
        Ticket carTicket = lot.parkVehicle(car, 0);      // needs medium+
        Ticket truckTicket = lot.parkVehicle(truck, 0);  // needs large

        lot.displayAvailability();

        // Exit with different pricing strategies
        System.out.println("\nUnparking with hourly pricing (bike, 3 hours):");
        lot.unparkVehicle(bikeTicket, 3, new HourlyRateStrategy(2.0));

        System.out.println("\nUnparking with flat pricing (truck):");
        lot.unparkVehicle(truckTicket, 5, new FlatRateStrategy(40.0));

        lot.displayAvailability();

        // Fill remaining large spots, then a second truck can't park
        System.out.println("\nFilling up, then trying one more truck:");
        lot.parkVehicle(VehicleFactory.create(VehicleType.TRUCK, "TRUCK-2"), 0); // takes 2-L1
        lot.parkVehicle(VehicleFactory.create(VehicleType.TRUCK, "TRUCK-3"), 0); // no large left
    }
}
