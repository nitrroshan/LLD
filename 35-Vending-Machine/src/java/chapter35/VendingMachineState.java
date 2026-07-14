package chapter35;

/**
 * State — the four user actions behave differently per state. A default no-op
 * dispense() lets only DispensingState perform the release.
 */
public interface VendingMachineState {
    void selectProduct(String code);
    void insertCoin(Coin coin);
    void payWith(PaymentStrategy strategy);
    void cancel();

    default void dispense() {
        // only meaningful in DispensingState
    }

    String name();
}
