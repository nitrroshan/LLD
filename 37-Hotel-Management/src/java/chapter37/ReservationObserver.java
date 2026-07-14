package chapter37;

/**
 * Observer — reacts to reservation lifecycle events without the hotel knowing
 * the concrete listener.
 */
public interface ReservationObserver {
    void onReserved(Reservation reservation);
    void onCheckedOut(Reservation reservation);
}
