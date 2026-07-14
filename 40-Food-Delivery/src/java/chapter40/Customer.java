package chapter40;

/**
 * A customer who places orders.
 */
public class Customer {
    private final String id;
    private final String name;
    private final Location location;

    public Customer(String id, String name, Location location) {
        this.id = id;
        this.name = name;
        this.location = location;
    }

    public String id() { return id; }
    public String name() { return name; }
    public Location location() { return location; }
}
