package chapter33;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== BookMyShow Demo ===\n");

        BookingSystem system = BookingSystem.getInstance();
        system.addListener(new AvailabilityDisplay());

        // Build a small screen: row 1 regular, row 2 premium, row 3 recliner (3 seats each).
        Screen screen = new Screen("SCR1", "Screen 1");
        for (int c = 1; c <= 3; c++) screen.addSeat(SeatFactory.createSeat(1, c, SeatType.REGULAR));
        for (int c = 1; c <= 3; c++) screen.addSeat(SeatFactory.createSeat(2, c, SeatType.PREMIUM));
        for (int c = 1; c <= 3; c++) screen.addSeat(SeatFactory.createSeat(3, c, SeatType.RECLINER));

        Theater theater = new Theater("TH1", "Downtown Cinema");
        theater.addScreen(screen);

        Movie movie = new Movie("M1", "Inception", 148);
        Show show = new Show("SH1", movie, screen, "Sat 7:00 PM");
        system.addShow(show);

        // Pricing: weekend surge (x1.5) over the base tier prices (Strategy + composition).
        PricingStrategy pricing = new WeekendSurgePricingStrategy(new SeatTypePricingStrategy(), 1.5);

        User alice = new User("U1", "Alice");
        User bob = new User("U2", "Bob");

        System.out.println("Available seats: " + show.availableCount() + "\n");

        // Alice books two regular seats.
        Booking b1 = system.book("SH1", Arrays.asList("R1C1", "R1C2"), alice, pricing);
        System.out.printf("  -> %s ($%.2f)%n%n", b1.getStatus(), b1.getAmount());

        // Bob tries to book an already-booked seat + a free one -> rejected (no double-booking).
        Booking b2 = system.book("SH1", Arrays.asList("R1C1", "R1C3"), bob, pricing);
        System.out.printf("  -> %s%n%n", b2.getStatus());

        // Bob books a recliner instead -> confirmed.
        Booking b3 = system.book("SH1", Arrays.asList("R3C1"), bob, pricing);
        System.out.printf("  -> %s ($%.2f)%n", b3.getStatus(), b3.getAmount());

        System.out.println("\nOne coordinator, pluggable pricing, factory-built seats,");
        System.out.println("observer-notified displays, and lock-safe double-booking prevention.");
    }
}
