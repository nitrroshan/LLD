package chapter33;

import java.util.LinkedHashMap;
import java.util.Map;

/**
 * A screen owns the seat layout (ids + types). Per-show availability lives in Show.
 */
public class Screen {
    private final String id;
    private final String name;
    private final Map<String, Seat> seats = new LinkedHashMap<>();

    public Screen(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() { return id; }
    public String getName() { return name; }

    public void addSeat(Seat seat) {
        seats.put(seat.getId(), seat);
    }

    public Seat getSeat(String seatId) {
        return seats.get(seatId);
    }

    public Map<String, Seat> getSeats() {
        return seats;
    }
}
