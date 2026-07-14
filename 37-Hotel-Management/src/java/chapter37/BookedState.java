package chapter37;

/**
 * Booked — reserved but the guest hasn't arrived. Check-in moves it to Occupied.
 */
public class BookedState implements RoomState {
    private static final BookedState INSTANCE = new BookedState();

    private BookedState() {}

    public static BookedState instance() {
        return INSTANCE;
    }

    @Override
    public void book(Room room) {
        System.out.println("    Room " + room.getNumber() + " is already booked");
    }

    @Override
    public void checkIn(Room room) {
        System.out.println("    Checked in to room " + room.getNumber());
        room.setState(OccupiedState.instance());
    }

    @Override
    public void checkOut(Room room) {
        System.out.println("    Guest hasn't checked in to room " + room.getNumber());
    }

    @Override
    public String name() {
        return "BOOKED";
    }
}
