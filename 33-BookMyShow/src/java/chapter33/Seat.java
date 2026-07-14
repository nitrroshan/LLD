package chapter33;

/**
 * A physical seat in a screen's layout (its state per show is tracked elsewhere).
 */
public class Seat {
    private final String id;
    private final int row;
    private final int number;
    private final SeatType type;

    public Seat(String id, int row, int number, SeatType type) {
        this.id = id;
        this.row = row;
        this.number = number;
        this.type = type;
    }

    public String getId() { return id; }
    public int getRow() { return row; }
    public int getNumber() { return number; }
    public SeatType getType() { return type; }
}
