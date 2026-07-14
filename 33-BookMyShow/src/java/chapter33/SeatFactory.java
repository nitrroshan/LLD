package chapter33;

/**
 * Factory Method — builds seats with a consistent id scheme, so callers don't
 * hand-wire ids/types.
 */
public class SeatFactory {
    public static Seat createSeat(int row, int number, SeatType type) {
        String id = "R" + row + "C" + number;
        return new Seat(id, row, number, type);
    }
}
