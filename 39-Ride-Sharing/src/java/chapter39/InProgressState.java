package chapter39;

/** The trip is underway; it can only be ended (not cancelled). */
public class InProgressState implements TripState {
    private static final InProgressState INSTANCE = new InProgressState();
    private InProgressState() {}
    public static InProgressState instance() { return INSTANCE; }

    @Override public void assignDriver(Trip trip, Driver driver) { System.out.println("    Trip already in progress"); }
    @Override public void start(Trip trip) { System.out.println("    Trip already started"); }

    @Override
    public void end(Trip trip) {
        trip.setState(CompletedState.instance());
        trip.notifyObservers("COMPLETED");
    }

    @Override public void cancel(Trip trip) { System.out.println("    Cannot cancel a trip in progress"); }

    @Override public String name() { return "IN_PROGRESS"; }
}
