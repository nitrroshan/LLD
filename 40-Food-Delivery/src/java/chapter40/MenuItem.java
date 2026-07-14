package chapter40;

/**
 * A single priced item on a restaurant's menu.
 */
public class MenuItem {
    private final String name;
    private final double price;

    public MenuItem(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String name() { return name; }
    public double price() { return price; }
}
