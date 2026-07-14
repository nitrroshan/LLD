package chapter22;

/**
 * Concrete Strategy — pays via PayPal.
 */
public class PayPalStrategy implements PaymentStrategy {
    private final String email;

    public PayPalStrategy(String email) {
        this.email = email;
    }

    @Override
    public void pay(double amount) {
        System.out.printf("  Paid $%.2f via PayPal account %s%n", amount, email);
    }
}
