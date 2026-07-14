package chapter37;

/**
 * Demo — a hotel with factory-built typed rooms, a room state machine, seasonal
 * pricing (Strategy), and guest/housekeeping observers.
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== Hotel Management Demo (Java) ===\n");

        PricingStrategy basePricing = new BasePricingStrategy();
        Hotel hotel = new Hotel("Grand LLD Hotel", basePricing);

        // Factory-built rooms.
        hotel.addRoom(RoomFactory.create(RoomType.SINGLE, "101"));
        hotel.addRoom(RoomFactory.create(RoomType.DOUBLE, "201"));
        hotel.addRoom(RoomFactory.create(RoomType.SUITE, "301"));

        // Observers.
        hotel.addObserver(new GuestNotifier());
        hotel.addObserver(new HousekeepingService());

        Guest alice = new Guest("G1", "Alice");

        // 1) Full lifecycle: book -> check-in -> check-out (State + Observer).
        System.out.println("Scenario 1: book -> check-in -> check-out");
        Reservation res = hotel.bookRoom(alice, RoomType.DOUBLE, 3);   // base: 150*3 = 450
        if (res != null) {
            hotel.checkIn(res);
            hotel.checkOut(res);
        }

        // 2) Switch to seasonal pricing and book the suite (Strategy).
        System.out.println("\nScenario 2: seasonal pricing");
        hotel.setPricing(new SeasonalPricingStrategy(1.5));
        Guest bob = new Guest("G2", "Bob");
        hotel.bookRoom(bob, RoomType.SUITE, 2);                        // 300*2*1.5 = 900 (left booked)

        // 3) No suite left — the only suite is booked by Bob.
        System.out.println("\nScenario 3: sold-out room type");
        Guest carol = new Guest("G3", "Carol");
        hotel.bookRoom(carol, RoomType.SUITE, 1);

        // 4) Illegal action refused by the state machine.
        System.out.println("\nScenario 4: check out a room nobody is in");
        Room single = hotel.searchAvailable(RoomType.SINGLE).get(0);
        single.checkOut();   // Available state refuses it
    }
}
