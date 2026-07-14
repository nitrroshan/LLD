package chapter44.after;

public class VipDiscount implements DiscountStrategy {
    public double discount(double subtotal) { return subtotal * 0.20; }
}
