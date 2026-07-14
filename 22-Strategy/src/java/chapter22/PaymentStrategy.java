package chapter22;

/**
 * Strategy — the common interface for a family of interchangeable payment
 * algorithms. Marked functional so a lambda can also serve as a strategy.
 */
@FunctionalInterface
public interface PaymentStrategy {
    void pay(double amount);
}
