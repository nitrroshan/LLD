package chapter44;

import java.util.List;

import chapter44.after.CustomerType;
import chapter44.after.DiscountStrategyFactory;
import chapter44.after.LineItem;
import chapter44.after.Order;
import chapter44.after.OrderProcessor;
import chapter44.after.ReceiptFormatter;
import chapter44.after.TaxCalculator;
import chapter44.before.OrderProcessorBefore;

/**
 * Runs the smelly BEFORE and the refactored AFTER on the same input and shows
 * their totals are identical — proving the refactoring preserved behavior.
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== Refactoring Demo (Java) ===\n");

        // BEFORE — the God class with a long method + switch-on-type.
        System.out.println("Before (smelly):");
        OrderProcessorBefore before = new OrderProcessorBefore();
        double beforeTotal = before.process(2, List.of(   // 2 = VIP (magic int)
                new OrderProcessorBefore.Line("Widget", 100, 2),
                new OrderProcessorBefore.Line("Gadget", 50, 1)));

        // AFTER — focused classes wired by a thin orchestrator.
        System.out.println("\nAfter (refactored):");
        Order order = new Order(List.of(
                new LineItem("Widget", 100, 2),
                new LineItem("Gadget", 50, 1)));
        OrderProcessor processor = new OrderProcessor(new TaxCalculator(0.08), new ReceiptFormatter());
        double afterTotal = processor.process(order, DiscountStrategyFactory.forType(CustomerType.VIP));

        System.out.printf("%nSame behavior? %b  (before=%.2f, after=%.2f)%n",
                Math.abs(beforeTotal - afterTotal) < 1e-9, beforeTotal, afterTotal);
    }
}
