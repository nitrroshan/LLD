package chapter22;

/**
 * Concrete Strategy — pays with cryptocurrency.
 */
public class CryptoStrategy implements PaymentStrategy {
    private final String wallet;

    public CryptoStrategy(String wallet) {
        this.wallet = wallet;
    }

    @Override
    public void pay(double amount) {
        System.out.printf("  Paid $%.2f in crypto from wallet %s%n", amount, wallet);
    }
}
