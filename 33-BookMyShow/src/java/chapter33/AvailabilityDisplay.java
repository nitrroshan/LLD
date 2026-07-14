package chapter33;

import java.util.List;

/**
 * Concrete Observer — a display board reacting to bookings and sell-outs.
 */
public class AvailabilityDisplay implements SeatAvailabilityListener {
    @Override
    public void onSeatsBooked(Show show, List<String> seatIds, User user) {
        System.out.printf("    [Display] %s booked %s. %d seats left for '%s'%n",
                user.getName(), seatIds, show.availableCount(), show.getMovie().getTitle());
    }

    @Override
    public void onSoldOut(Show show) {
        System.out.printf("    [Display] '%s' (%s) is now SOLD OUT%n",
                show.getMovie().getTitle(), show.getStartTime());
    }
}
