package chapter39;

/**
 * State — the trip lifecycle. Each concrete state defines which actions are
 * legal and what transition follows; illegal actions are refused.
 */
public interface TripState {
    void assignDriver(Trip trip, Driver driver);
    void start(Trip trip);
    void end(Trip trip);
    void cancel(Trip trip);
    String name();
}
