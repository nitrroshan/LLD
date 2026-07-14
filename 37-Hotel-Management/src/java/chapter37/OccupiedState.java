package chapter37;

/**
 * Occupied — a guest is staying. Check-out frees the room back to Available.
 */
public class OccupiedState implements RoomState {
    private static final OccupiedState INSTANCE = new OccupiedState();

    private OccupiedState() {}

    public static OccupiedState instance() {
        return INSTANCE;
    }

    @Override
    public void book(Room room) {
        System.out.println("    Room " + room.getNumber() + " is occupied");
    }

    @Override
    public void checkIn(Room room) {
        System.out.println("    Already checked in to room " + room.getNumber());
    }

    @Override
    public void checkOut(Room room) {
        System.out.println("    Checked out of room " + room.getNumber());
        room.setState(AvailableState.instance());
    }

    @Override
    public String name() {
        return "OCCUPIED";
    }
}
