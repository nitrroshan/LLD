package chapter36;

/**
 * Idle — no card inserted. Only inserting a card does anything.
 */
public class IdleState implements ATMState {
    private final ATM atm;

    public IdleState(ATM atm) {
        this.atm = atm;
    }

    @Override
    public void insertCard(Card card) {
        atm.setCurrentCard(card);
        System.out.println("  Card inserted (" + card.getCardNumber() + "). Enter PIN.");
        atm.setState(atm.getHasCardState());
    }

    @Override
    public void enterPin(String pin) {
        System.out.println("  Insert a card first");
    }

    @Override
    public void performTransaction(Transaction transaction) {
        System.out.println("  Insert a card first");
    }

    @Override
    public void ejectCard() {
        System.out.println("  No card to eject");
    }

    @Override
    public String name() {
        return "IDLE";
    }
}
