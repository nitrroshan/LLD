package chapter39;

/**
 * Observer — notifies the rider of status changes.
 */
public class RiderNotifier implements TripObserver {
    @Override
    public void onStatusChanged(Trip trip, String status) {
        System.out.println("    [Rider " + trip.rider().name() + "] trip is now " + status);
    }
}
