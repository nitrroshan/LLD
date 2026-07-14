package chapter37;

/**
 * Available — the room is free. Booking it moves it to Booked. Stateless
 * singleton shared by every room.
 */
public class AvailableState implements RoomState {
    private static final AvailableState INSTANCE = new AvailableState();

    private AvailableState() {}

    public static AvailableState instance() {
        return INSTANCE;
    }

    @Override
    public void book(Room room) {
        System.out.println("    Room " + room.getNumber() + " booked");
        room.setState(BookedState.instance());
    }

    @Override
    public void checkIn(Room room) {
        System.out.println("    Room " + room.getNumber() + " is not booked yet");
    }

    @Override
    public void checkOut(Room room) {
        System.out.println("    Room " + room.getNumber() + " is not occupied");
    }

    @Override
    public String name() {
        return "AVAILABLE";
    }
}
