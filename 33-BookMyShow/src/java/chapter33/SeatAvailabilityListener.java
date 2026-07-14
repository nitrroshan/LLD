package chapter33;

import java.util.List;

/**
 * Observer — notified as seats are booked or a show sells out.
 */
public interface SeatAvailabilityListener {
    void onSeatsBooked(Show show, List<String> seatIds, User user);
    void onSoldOut(Show show);
}
