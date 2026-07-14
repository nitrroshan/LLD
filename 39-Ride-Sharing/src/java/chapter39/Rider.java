package chapter39;

/**
 * A rider requesting trips.
 */
public class Rider {
    private final String id;
    private final String name;
    private Location location;

    public Rider(String id, String name, Location location) {
        this.id = id;
        this.name = name;
        this.location = location;
    }

    public String id() { return id; }
    public String name() { return name; }
    public Location location() { return location; }
    public void setLocation(Location location) { this.location = location; }
}
