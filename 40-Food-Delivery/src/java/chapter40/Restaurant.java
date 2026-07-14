package chapter40;

/**
 * A restaurant with a menu and a location.
 */
public class Restaurant {
    private final String id;
    private final String name;
    private final Location location;
    private final Menu menu;

    public Restaurant(String id, String name, Location location, Menu menu) {
        this.id = id;
        this.name = name;
        this.location = location;
        this.menu = menu;
    }

    public String id() { return id; }
    public String name() { return name; }
    public Location location() { return location; }
    public Menu menu() { return menu; }
}
