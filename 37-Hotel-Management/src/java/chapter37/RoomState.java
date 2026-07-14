package chapter37;

/**
 * State — each concrete state defines how the three room actions behave and
 * what transition follows. Illegal actions are refused by the current state.
 */
public interface RoomState {
    void book(Room room);
    void checkIn(Room room);
    void checkOut(Room room);
    String name();
}
