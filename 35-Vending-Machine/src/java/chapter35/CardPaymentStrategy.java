package chapter35;

/**
 * Concrete Strategy — pay by card.
 */
public class CardPaymentStrategy implements PaymentStrategy {
    private final String cardNumber;

    public CardPaymentStrategy(String cardNumber) {
        this.cardNumber = cardNumber;
    }

    @Override
    public boolean pay(int amountCents) {
        String masked = "****" + cardNumber.substring(cardNumber.length() - 4);
        System.out.printf("    Card %s charged $%.2f%n", masked, amountCents / 100.0);
        return true;
    }
}
