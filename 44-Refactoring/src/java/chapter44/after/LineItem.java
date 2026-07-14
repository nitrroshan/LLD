package chapter44.after;

/** A menu line item that knows its own subtotal (Tell, Don't Ask). */
public class LineItem {
    private final String name;
    private final double price;
    private final int quantity;

    public LineItem(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public String name() { return name; }
    public int quantity() { return quantity; }
    public double subtotal() { return price * quantity; }   // moved onto the data
}
