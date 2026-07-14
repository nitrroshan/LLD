package chapter39;

/** The ride has been requested but no driver is assigned yet. */
public class RequestedState implements TripState {
    private static final RequestedState INSTANCE = new RequestedState();
    private RequestedState() {}
    public static RequestedState instance() { return INSTANCE; }

    @Override
    public void assignDriver(Trip trip, Driver driver) {
        trip.setDriver(driver);
        trip.setState(DriverAssignedState.instance());
        trip.notifyObservers("DRIVER_ASSIGNED");
    }

    @Override public void start(Trip trip) { System.out.println("    No driver assigned yet"); }
    @Override public void end(Trip trip) { System.out.println("    Trip hasn't started"); }

    @Override
    public void cancel(Trip trip) {
        trip.setState(CancelledState.instance());
        trip.notifyObservers("CANCELLED");
    }

    @Override public String name() { return "REQUESTED"; }
}
