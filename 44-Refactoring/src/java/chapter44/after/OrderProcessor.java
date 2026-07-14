package chapter44.after;

/**
 * AFTER — a thin orchestrator. It wires the focused collaborators together;
 * each does one job. Pricing, tax, and formatting can now change independently.
 */
public class OrderProcessor {
    private final TaxCalculator taxCalculator;
    private final ReceiptFormatter formatter;

    public OrderProcessor(TaxCalculator taxCalculator, ReceiptFormatter formatter) {
        this.taxCalculator = taxCalculator;
        this.formatter = formatter;
    }

    public double process(Order order, DiscountStrategy discountStrategy) {
        double subtotal = order.subtotal();
        double discount = discountStrategy.discount(subtotal);        // Strategy
        double net = subtotal - discount;
        double total = net + taxCalculator.tax(net);                  // SRP
        formatter.print(order, subtotal, discount, total);            // SRP
        return total;
    }
}
