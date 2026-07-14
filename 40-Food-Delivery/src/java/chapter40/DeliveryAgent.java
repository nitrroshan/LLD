package chapter40;

/**
 * A delivery agent with a location and availability.
 */
public class DeliveryAgent {
    private final String id;
    private final String name;
    private Location location;
    private boolean available = true;

    public DeliveryAgent(String id, String name, Location location) {
        this.id = id;
        this.name = name;
        this.location = location;
    }

    public String id() { return id; }
    public String name() { return name; }
    public Location location() { return location; }
    public boolean isAvailable() { return available; }
    public void setAvailable(boolean available) { this.available = available; }
}
