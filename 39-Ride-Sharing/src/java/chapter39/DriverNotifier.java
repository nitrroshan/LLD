package chapter39;

/**
 * Observer — notifies the assigned driver of status changes.
 */
public class DriverNotifier implements TripObserver {
    @Override
    public void onStatusChanged(Trip trip, String status) {
        String driver = trip.driver() == null ? "(unassigned)" : trip.driver().name();
        System.out.println("    [Driver " + driver + "] trip is now " + status);
    }
}
