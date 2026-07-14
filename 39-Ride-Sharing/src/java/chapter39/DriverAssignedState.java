package chapter39;

/** A driver is assigned and en route; the trip can start or be cancelled. */
public class DriverAssignedState implements TripState {
    private static final DriverAssignedState INSTANCE = new DriverAssignedState();
    private DriverAssignedState() {}
    public static DriverAssignedState instance() { return INSTANCE; }

    @Override public void assignDriver(Trip trip, Driver driver) { System.out.println("    Driver already assigned"); }

    @Override
    public void start(Trip trip) {
        trip.setState(InProgressState.instance());
        trip.notifyObservers("IN_PROGRESS");
    }

    @Override public void end(Trip trip) { System.out.println("    Trip hasn't started"); }

    @Override
    public void cancel(Trip trip) {
        trip.setState(CancelledState.instance());
        trip.notifyObservers("CANCELLED");
    }

    @Override public String name() { return "DRIVER_ASSIGNED"; }
}
