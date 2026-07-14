package chapter39;

/**
 * A driver with a vehicle, current location, availability, and a rolling rating.
 */
public class Driver {
    private final String id;
    private final String name;
    private final Vehicle vehicle;
    private Location location;
    private boolean available = true;
    private double rating = 5.0;
    private int ratingCount = 1;

    public Driver(String id, String name, Vehicle vehicle, Location location) {
        this.id = id;
        this.name = name;
        this.vehicle = vehicle;
        this.location = location;
    }

    public String id() { return id; }
    public String name() { return name; }
    public Vehicle vehicle() { return vehicle; }
    public Location location() { return location; }
    public void setLocation(Location location) { this.location = location; }
    public boolean isAvailable() { return available; }
    public void setAvailable(boolean available) { this.available = available; }
    public double rating() { return rating; }

    public void addRating(int stars) {
        rating = (rating * ratingCount + stars) / (ratingCount + 1);
        ratingCount++;
    }
}
