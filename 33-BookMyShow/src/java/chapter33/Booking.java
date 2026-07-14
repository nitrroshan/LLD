package chapter33;

import java.util.List;

/**
 * The record of a booking attempt (confirmed or failed).
 */
public class Booking {
    private final String id;
    private final Show show;
    private final List<Seat> seats;
    private final User user;
    private final double amount;
    private final BookingStatus status;

    public Booking(String id, Show show, List<Seat> seats, User user, double amount, BookingStatus status) {
        this.id = id;
        this.show = show;
        this.seats = seats;
        this.user = user;
        this.amount = amount;
        this.status = status;
    }

    public String getId() { return id; }
    public Show getShow() { return show; }
    public List<Seat> getSeats() { return seats; }
    public User getUser() { return user; }
    public double getAmount() { return amount; }
    public BookingStatus getStatus() { return status; }
}
