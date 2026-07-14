package chapter45;

/** A payment gateway abstraction — the seam that makes OrderService testable. */
public interface PaymentGateway {
    boolean charge(double amount);
}
