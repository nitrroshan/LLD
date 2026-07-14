package chapter28;

/**
 * Strategy — computes the parking fee. Implementations are swapped at exit.
 */
public interface PricingStrategy {
    double calculatePrice(Ticket ticket, long exitTime);
}
