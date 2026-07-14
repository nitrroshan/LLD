package chapter36;

/**
 * A physical card. Carries the card number and the account it maps to.
 */
public class Card {
    private final String cardNumber;
    private final String accountNumber;

    public Card(String cardNumber, String accountNumber) {
        this.cardNumber = cardNumber;
        this.accountNumber = accountNumber;
    }

    public String getCardNumber() {
        return cardNumber;
    }

    public String getAccountNumber() {
        return accountNumber;
    }
}
