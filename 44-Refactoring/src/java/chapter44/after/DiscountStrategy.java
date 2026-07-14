package chapter44.after;

/**
 * Strategy — the discount rule. Replaces the switch-on-type; a new tier is a new
 * class (Open/Closed), never an edit to a conditional.
 */
public interface DiscountStrategy {
    double discount(double subtotal);
}
