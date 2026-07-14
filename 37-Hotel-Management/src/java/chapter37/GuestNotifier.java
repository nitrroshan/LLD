package chapter37;

/**
 * Observer — messages the guest on booking and check-out.
 */
public class GuestNotifier implements ReservationObserver {
    @Override
    public void onReserved(Reservation r) {
        System.out.printf("    [SMS to %s] Booking %s confirmed: room %s for %d night(s) ($%.0f)%n",
                r.getGuest().getName(), r.getId(), r.getRoom().getNumber(), r.getNights(), r.getAmount());
    }

    @Override
    public void onCheckedOut(Reservation r) {
        System.out.printf("    [SMS to %s] Thanks for staying with us! (%s)%n",
                r.getGuest().getName(), r.getId());
    }
}
