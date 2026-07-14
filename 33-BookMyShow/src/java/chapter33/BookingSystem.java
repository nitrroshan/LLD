package chapter33;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Singleton coordinator. Owns shows and runs the double-booking-safe workflow:
 * lock seats -> price via the injected strategy -> pay -> confirm (or release),
 * then notify observers.
 */
public class BookingSystem {
    private static final BookingSystem INSTANCE = new BookingSystem();

    private final Map<String, Show> shows = new HashMap<>();
    private final List<SeatAvailabilityListener> listeners = new ArrayList<>();
    private int bookingCounter = 0;

    private BookingSystem() {
    }

    public static BookingSystem getInstance() {
        return INSTANCE;
    }

    public void addShow(Show show) {
        shows.put(show.getId(), show);
    }

    public void addListener(SeatAvailabilityListener listener) {
        listeners.add(listener);
    }

    public Booking book(String showId, List<String> seatIds, User user, PricingStrategy pricing) {
        Show show = shows.get(showId);
        if (show == null) {
            System.out.println("  Booking failed: unknown show");
            return new Booking(nextId(), null, new ArrayList<>(), user, 0, BookingStatus.FAILED);
        }

        // 1) Lock (critical section) — reject if any requested seat is taken.
        if (!show.lockSeats(seatIds, user.getId())) {
            System.out.printf("  %s: requested seats %s not available%n", user.getName(), seatIds);
            return new Booking(nextId(), show, new ArrayList<>(), user, 0, BookingStatus.FAILED);
        }

        // 2) Price via the chosen strategy.
        List<Seat> seats = new ArrayList<>();
        double amount = 0;
        for (String seatId : seatIds) {
            Seat seat = show.getScreen().getSeat(seatId);
            seats.add(seat);
            amount += pricing.calculatePrice(seat, show);
        }

        // 3) Pay, then confirm or release.
        System.out.printf("  %s booking %s (%s):%n", user.getName(), seatIds, show.getMovie().getTitle());
        Payment payment = new Payment(amount);
        if (payment.process()) {
            show.confirmSeats(seatIds, user.getId());
            Booking booking = new Booking(nextId(), show, seats, user, amount, BookingStatus.CONFIRMED);
            notifyBooked(show, seatIds, user);
            if (show.isSoldOut()) {
                notifySoldOut(show);
            }
            return booking;
        } else {
            show.releaseSeats(seatIds, user.getId());
            return new Booking(nextId(), show, new ArrayList<>(), user, 0, BookingStatus.FAILED);
        }
    }

    private void notifyBooked(Show show, List<String> seatIds, User user) {
        for (SeatAvailabilityListener listener : listeners) {
            listener.onSeatsBooked(show, seatIds, user);
        }
    }

    private void notifySoldOut(Show show) {
        for (SeatAvailabilityListener listener : listeners) {
            listener.onSoldOut(show);
        }
    }

    private String nextId() {
        return "B" + (++bookingCounter);
    }
}
