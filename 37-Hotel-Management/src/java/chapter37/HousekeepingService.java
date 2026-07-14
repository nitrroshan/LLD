package chapter37;

/**
 * Observer — schedules cleaning when a guest checks out.
 */
public class HousekeepingService implements ReservationObserver {
    @Override
    public void onReserved(Reservation r) {
        // Housekeeping doesn't care about new bookings.
    }

    @Override
    public void onCheckedOut(Reservation r) {
        System.out.println("    [Housekeeping] Schedule cleaning for room " + r.getRoom().getNumber());
    }
}
