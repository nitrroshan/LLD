package chapter37;

/**
 * The lifecycle status of a reservation (separate from the room's physical State).
 */
public enum ReservationStatus {
    CONFIRMED,
    CHECKED_IN,
    COMPLETED,
    CANCELLED
}
