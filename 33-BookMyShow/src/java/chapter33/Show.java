package chapter33;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * A movie on a screen at a time. Owns the PER-SHOW seat status and the seat
 * locking that prevents double-booking. The lock/confirm/release methods are
 * synchronized — the critical section for concurrent bookings.
 */
public class Show {
    private final String id;
    private final Movie movie;
    private final Screen screen;
    private final String startTime;
    private final Map<String, SeatStatus> status = new HashMap<>();
    private final Map<String, String> lockedBy = new HashMap<>();

    public Show(String id, Movie movie, Screen screen, String startTime) {
        this.id = id;
        this.movie = movie;
        this.screen = screen;
        this.startTime = startTime;
        for (String seatId : screen.getSeats().keySet()) {
            status.put(seatId, SeatStatus.AVAILABLE);
        }
    }

    public String getId() { return id; }
    public Movie getMovie() { return movie; }
    public Screen getScreen() { return screen; }
    public String getStartTime() { return startTime; }

    /** Atomically lock all requested seats, or none. Returns false if any is taken. */
    public synchronized boolean lockSeats(List<String> seatIds, String userId) {
        for (String seatId : seatIds) {
            if (status.getOrDefault(seatId, SeatStatus.BOOKED) != SeatStatus.AVAILABLE) {
                return false;   // some seat unavailable — lock nothing
            }
        }
        for (String seatId : seatIds) {
            status.put(seatId, SeatStatus.LOCKED);
            lockedBy.put(seatId, userId);
        }
        return true;
    }

    public synchronized void confirmSeats(List<String> seatIds, String userId) {
        for (String seatId : seatIds) {
            if (userId.equals(lockedBy.get(seatId))) {
                status.put(seatId, SeatStatus.BOOKED);
                lockedBy.remove(seatId);
            }
        }
    }

    public synchronized void releaseSeats(List<String> seatIds, String userId) {
        for (String seatId : seatIds) {
            if (userId.equals(lockedBy.get(seatId))) {
                status.put(seatId, SeatStatus.AVAILABLE);
                lockedBy.remove(seatId);
            }
        }
    }

    public synchronized boolean isSoldOut() {
        for (SeatStatus s : status.values()) {
            if (s == SeatStatus.AVAILABLE) {
                return false;
            }
        }
        return true;
    }

    public synchronized int availableCount() {
        int count = 0;
        for (SeatStatus s : status.values()) {
            if (s == SeatStatus.AVAILABLE) {
                count++;
            }
        }
        return count;
    }
}
