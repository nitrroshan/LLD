package chapter39;

/** Terminal — the trip finished successfully. */
public class CompletedState implements TripState {
    private static final CompletedState INSTANCE = new CompletedState();
    private CompletedState() {}
    public static CompletedState instance() { return INSTANCE; }

    @Override public void assignDriver(Trip trip, Driver driver) { rejected(); }
    @Override public void start(Trip trip) { rejected(); }
    @Override public void end(Trip trip) { rejected(); }
    @Override public void cancel(Trip trip) { rejected(); }
    @Override public String name() { return "COMPLETED"; }

    private void rejected() { System.out.println("    Trip is already completed"); }
}
