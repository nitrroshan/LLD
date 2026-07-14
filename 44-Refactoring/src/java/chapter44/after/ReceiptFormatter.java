package chapter44.after;

/** Single responsibility: presentation. Formatting is separated from calculation. */
public class ReceiptFormatter {
    public void print(Order order, double subtotal, double discount, double total) {
        System.out.println("  [after]  === RECEIPT ===");
        for (LineItem item : order.items()) {
            System.out.printf("  [after]  %s x%d = %.2f%n",
                    item.name(), item.quantity(), item.subtotal());
        }
        System.out.printf("  [after]  subtotal=%.2f discount=%.2f total=%.2f%n",
                subtotal, discount, total);
    }
}
