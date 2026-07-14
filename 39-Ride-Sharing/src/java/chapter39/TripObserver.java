package chapter39;

/**
 * Observer — reacts to trip status changes without the trip knowing the listener.
 */
public interface TripObserver {
    void onStatusChanged(Trip trip, String status);
}
