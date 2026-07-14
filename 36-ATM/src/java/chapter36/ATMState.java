package chapter36;

/**
 * State — each concrete state defines how the four ATM actions behave and what
 * transition follows. Acting out of order is refused by the current state.
 */
public interface ATMState {
    void insertCard(Card card);
    void enterPin(String pin);
    void performTransaction(Transaction transaction);
    void ejectCard();
    String name();
}
