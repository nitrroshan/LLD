package chapter35;

/**
 * Accepted (and one unaccepted) coin denominations, valued in cents.
 * PENNY has no handler in the coin chain, so it is rejected — demonstrating
 * the Chain of Responsibility's "fell off the end" case.
 */
public enum Coin {
    PENNY(1),
    NICKEL(5),
    DIME(10),
    QUARTER(25),
    DOLLAR(100);

    private final int value;

    Coin(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}
