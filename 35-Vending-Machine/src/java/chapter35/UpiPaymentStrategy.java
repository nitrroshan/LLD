package chapter35;

/**
 * Concrete Strategy — pay by UPI. Adding this required no change to the machine
 * or its states.
 */
public class UpiPaymentStrategy implements PaymentStrategy {
    private final String vpa;

    public UpiPaymentStrategy(String vpa) {
        this.vpa = vpa;
    }

    @Override
    public boolean pay(int amountCents) {
        System.out.printf("    UPI %s paid $%.2f%n", vpa, amountCents / 100.0);
        return true;
    }
}
