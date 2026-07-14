package chapter37;

/**
 * A hotel room. Holds its type and amenities, and delegates all lifecycle
 * actions to its current State. Starts Available.
 */
public class Room {
    private final String number;
    private final RoomType type;
    private final String amenities;
    private RoomState state = AvailableState.instance();

    public Room(String number, RoomType type, String amenities) {
        this.number = number;
        this.type = type;
        this.amenities = amenities;
    }

    // Lifecycle actions — delegate to the current state.
    public void book() { state.book(this); }
    public void checkIn() { state.checkIn(this); }
    public void checkOut() { state.checkOut(this); }

    public void setState(RoomState state) { this.state = state; }
    public String getNumber() { return number; }
    public RoomType getType() { return type; }
    public String getAmenities() { return amenities; }
    public String stateName() { return state.name(); }
}
