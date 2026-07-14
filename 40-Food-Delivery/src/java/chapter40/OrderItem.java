package chapter40;

/**
 * A line item in an order: a menu item and how many.
 */
public class OrderItem {
    private final MenuItem item;
    private final int quantity;

    public OrderItem(MenuItem item, int quantity) {
        this.item = item;
        this.quantity = quantity;
    }

    public MenuItem item() { return item; }
    public int quantity() { return quantity; }
    public double subtotal() { return item.price() * quantity; }
}
