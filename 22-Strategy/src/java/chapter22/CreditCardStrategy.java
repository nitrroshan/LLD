package chapter22;

/**
 * Concrete Strategy — pays with a credit card.
 */
public class CreditCardStrategy implements PaymentStrategy {
    private final String cardNumber;

    public CreditCardStrategy(String cardNumber) {
        this.cardNumber = cardNumber;
    }

    @Override
    public void pay(double amount) {
        String masked = "****" + cardNumber.substring(cardNumber.length() - 4);
        System.out.printf("  Paid $%.2f with credit card %s%n", amount, masked);
    }
}
