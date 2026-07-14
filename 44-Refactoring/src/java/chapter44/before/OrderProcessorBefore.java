package chapter44.before;

import java.util.List;

/**
 * BEFORE — a smelly God class. One long method mixes: subtotal calc, a
 * switch-on-type for discounts, an inline magic-number tax, and inline receipt
 * formatting. It has many reasons to change (pricing, tax, formatting, tiers).
 *
 * Smells: God Class, Long Method, Switch-on-Type, Magic Numbers, mixed concerns.
 */
public class OrderProcessorBefore {

    // A line item as a raw array-ish tuple — primitive obsession, too.
    public static class Line {
        public final String name;
        public final double price;
        public final int qty;
        public Line(String name, double price, int qty) {
            this.name = name; this.price = price; this.qty = qty;
        }
    }

    /** customerType: 0=REGULAR, 1=PREMIUM, 2=VIP (magic ints — another smell). */
    public double process(int customerType, List<Line> lines) {
        double subtotal = 0;
        for (Line l : lines) {
            subtotal += l.price * l.qty;
        }

        // Discount: a switch on a type code (the classic smell).
        double discount;
        if (customerType == 0) {
            discount = 0;
        } else if (customerType == 1) {
            discount = subtotal * 0.10;
        } else if (customerType == 2) {
            discount = subtotal * 0.20;
        } else {
            discount = 0;
        }

        double taxed = (subtotal - discount) * 1.08;   // inline tax + magic number

        // Inline receipt formatting — presentation tangled with calculation.
        System.out.println("  [before] === RECEIPT ===");
        for (Line l : lines) {
            System.out.printf("  [before] %s x%d = %.2f%n", l.name, l.qty, l.price * l.qty);
        }
        System.out.printf("  [before] subtotal=%.2f discount=%.2f total=%.2f%n",
                subtotal, discount, taxed);

        return taxed;
    }
}
