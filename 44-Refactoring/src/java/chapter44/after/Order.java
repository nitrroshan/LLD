package chapter44.after;

import java.util.List;

/** An order that computes its own subtotal (Move Method — no feature envy). */
public class Order {
    private final List<LineItem> items;

    public Order(List<LineItem> items) {
        this.items = items;
    }

    public List<LineItem> items() { return items; }

    public double subtotal() {
        double sum = 0;
        for (LineItem item : items) sum += item.subtotal();
        return sum;
    }
}
