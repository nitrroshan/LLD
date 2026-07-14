package chapter44.after;

public class PremiumDiscount implements DiscountStrategy {
    public double discount(double subtotal) { return subtotal * 0.10; }
}
