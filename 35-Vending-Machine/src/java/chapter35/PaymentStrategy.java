package chapter35;

/**
 * Strategy — an instant payment method that tenders the full amount at once.
 */
public interface PaymentStrategy {
    boolean pay(int amountCents);
}
