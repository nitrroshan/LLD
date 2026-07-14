package chapter36;

/**
 * Authenticated — PIN verified. Runs transactions and ejects the card.
 */
public class AuthenticatedState implements ATMState {
    private final ATM atm;

    public AuthenticatedState(ATM atm) {
        this.atm = atm;
    }

    @Override
    public void insertCard(Card card) {
        System.out.println("  Finish the current session first");
    }

    @Override
    public void enterPin(String pin) {
        System.out.println("  Already authenticated");
    }

    @Override
    public void performTransaction(Transaction transaction) {
        System.out.println("  > " + transaction.description());
        transaction.execute();
    }

    @Override
    public void ejectCard() {
        System.out.println("  Session ended. Card ejected.");
        atm.resetSession();
        atm.setState(atm.getIdleState());
    }

    @Override
    public String name() {
        return "AUTHENTICATED";
    }
}
