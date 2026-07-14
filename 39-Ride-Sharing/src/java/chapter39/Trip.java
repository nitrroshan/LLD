package chapter39;

import java.util.ArrayList;
import java.util.List;

/**
 * Context — a trip. Holds the rider, driver, pickup/drop, fare, current State,
 * and observers. All lifecycle actions delegate to the current state.
 */
public class Trip {
    private final Rider rider;
    private Driver driver;
    private final Location pickup;
    private final Location drop;
    private double fare;
    private TripState state = RequestedState.instance();
    private final List<TripObserver> observers = new ArrayList<>();

    public Trip(Rider rider, Location pickup, Location drop) {
        this.rider = rider;
        this.pickup = pickup;
        this.drop = drop;
    }

    public void addObserver(TripObserver observer) { observers.add(observer); }
    public void notifyObservers(String status) {
        for (TripObserver o : observers) o.onStatusChanged(this, status);
    }

    // Lifecycle actions — delegate to the current state.
    public void assignDriver(Driver driver) { state.assignDriver(this, driver); }
    public void start() { state.start(this); }
    public void end() { state.end(this); }
    public void cancel() { state.cancel(this); }

    public void setState(TripState state) { this.state = state; }
    public String stateName() { return state.name(); }
    public Rider rider() { return rider; }
    public Driver driver() { return driver; }
    public void setDriver(Driver driver) { this.driver = driver; }
    public Location pickup() { return pickup; }
    public Location drop() { return drop; }
    public double fare() { return fare; }
    public void setFare(double fare) { this.fare = fare; }
}
