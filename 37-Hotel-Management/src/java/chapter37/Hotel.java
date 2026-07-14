package chapter37;

import java.util.ArrayList;
import java.util.List;

/**
 * Coordinator — owns the rooms, reservations, observers, and pricing strategy.
 * Handles search, booking, check-in, and check-out, and fires events to observers.
 */
public class Hotel {
    private final String name;
    private final List<Room> rooms = new ArrayList<>();
    private final List<Reservation> reservations = new ArrayList<>();
    private final List<ReservationObserver> observers = new ArrayList<>();
    private PricingStrategy pricing;
    private int counter = 0;

    public Hotel(String name, PricingStrategy pricing) {
        this.name = name;
        this.pricing = pricing;
    }

    public void addRoom(Room room) { rooms.add(room); }
    public void addObserver(ReservationObserver observer) { observers.add(observer); }
    public void setPricing(PricingStrategy pricing) { this.pricing = pricing; }

    public List<Room> searchAvailable(RoomType type) {
        List<Room> result = new ArrayList<>();
        for (Room room : rooms) {
            if (room.getType() == type && room.stateName().equals("AVAILABLE")) {
                result.add(room);
            }
        }
        return result;
    }

    public Reservation bookRoom(Guest guest, RoomType type, int nights) {
        List<Room> available = searchAvailable(type);
        if (available.isEmpty()) {
            System.out.println("  No " + type + " rooms available");
            return null;
        }
        Room room = available.get(0);
        room.book();                                         // State: Available -> Booked
        double amount = pricing.calculatePrice(type, nights); // Strategy
        String id = "R" + (++counter);
        Reservation reservation = new Reservation(id, guest, room, nights, amount);
        reservations.add(reservation);
        for (ReservationObserver observer : observers) {      // Observer
            observer.onReserved(reservation);
        }
        return reservation;
    }

    public void checkIn(Reservation reservation) {
        reservation.getRoom().checkIn();                     // State: Booked -> Occupied
        reservation.setStatus(ReservationStatus.CHECKED_IN);
    }

    public void checkOut(Reservation reservation) {
        reservation.getRoom().checkOut();                    // State: Occupied -> Available
        reservation.setStatus(ReservationStatus.COMPLETED);
        for (ReservationObserver observer : observers) {      // Observer
            observer.onCheckedOut(reservation);
        }
    }

    public String getName() { return name; }
}
