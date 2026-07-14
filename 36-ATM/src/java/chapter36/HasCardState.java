package chapter36;

/**
 * HasCard — a card is inserted, awaiting PIN. Limited attempts, then the card
 * is retained and the ATM returns to Idle.
 */
public class HasCardState implements ATMState {
    private static final int MAX_ATTEMPTS = 3;
    private final ATM atm;

    public HasCardState(ATM atm) {
        this.atm = atm;
    }

    @Override
    public void insertCard(Card card) {
        System.out.println("  A card is already inserted");
    }

    @Override
    public void enterPin(String pin) {
        Account account = atm.getBank().authenticate(atm.getCurrentCard(), pin);
        if (account != null) {
            atm.setCurrentAccount(account);
            System.out.println("  PIN accepted. Choose a transaction.");
            atm.setState(atm.getAuthenticatedState());
            return;
        }
        atm.incrementPinAttempts();
        if (atm.getPinAttempts() >= MAX_ATTEMPTS) {
            System.out.println("  Too many wrong PIN attempts. Card retained.");
            atm.resetSession();
            atm.setState(atm.getIdleState());
        } else {
            System.out.println("  Wrong PIN. Attempts left: " + (MAX_ATTEMPTS - atm.getPinAttempts()));
        }
    }

    @Override
    public void performTransaction(Transaction transaction) {
        System.out.println("  Authenticate with your PIN first");
    }

    @Override
    public void ejectCard() {
        System.out.println("  Card ejected");
        atm.resetSession();
        atm.setState(atm.getIdleState());
    }

    @Override
    public String name() {
        return "HAS_CARD";
    }
}
