package chapter39;

/** Terminal — the trip was cancelled. */
public class CancelledState implements TripState {
    private static final CancelledState INSTANCE = new CancelledState();
    private CancelledState() {}
    public static CancelledState instance() { return INSTANCE; }

    @Override public void assignDriver(Trip trip, Driver driver) { rejected(); }
    @Override public void start(Trip trip) { rejected(); }
    @Override public void end(Trip trip) { rejected(); }
    @Override public void cancel(Trip trip) { rejected(); }
    @Override public String name() { return "CANCELLED"; }

    private void rejected() { System.out.println("    Trip is already cancelled"); }
}
