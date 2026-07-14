package chapter45;

/** Strategy under test — pure, injected, trivially testable. */
public interface DiscountStrategy {
    double discount(double subtotal);
}
