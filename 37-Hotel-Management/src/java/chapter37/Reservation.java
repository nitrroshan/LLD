package chapter37;

/**
 * A booking record: who, which room, how many nights, the amount, and status.
 */
public class Reservation {
    private final String id;
    private final Guest guest;
    private final Room room;
    private final int nights;
    private final double amount;
    private ReservationStatus status = ReservationStatus.CONFIRMED;

    public Reservation(String id, Guest guest, Room room, int nights, double amount) {
        this.id = id;
        this.guest = guest;
        this.room = room;
        this.nights = nights;
        this.amount = amount;
    }

    public String getId() { return id; }
    public Guest getGuest() { return guest; }
    public Room getRoom() { return room; }
    public int getNights() { return nights; }
    public double getAmount() { return amount; }
    public ReservationStatus getStatus() { return status; }
    public void setStatus(ReservationStatus status) { this.status = status; }
}
