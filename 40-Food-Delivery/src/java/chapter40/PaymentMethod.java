package chapter40;

/**
 * A way to pay for an order. Concrete methods are built by the PaymentFactory.
 */
public interface PaymentMethod {
    boolean pay(double amount);
}
