package chapter36;

/**
 * Context — the ATM terminal. Holds the current state, the inserted card and
 * authenticated account, the cash dispenser, and the bank. All user actions
 * delegate to the current state (State pattern).
 */
public class ATM {
    private final BankService bank;
    private final CashDispenser dispenser;

    private final ATMState idleState;
    private final ATMState hasCardState;
    private final ATMState authenticatedState;

    private ATMState current;
    private Card currentCard;
    private Account currentAccount;
    private int pinAttempts = 0;

    public ATM(BankService bank, CashDispenser dispenser) {
        this.bank = bank;
        this.dispenser = dispenser;
        this.idleState = new IdleState(this);
        this.hasCardState = new HasCardState(this);
        this.authenticatedState = new AuthenticatedState(this);
        this.current = idleState;
    }

    // User actions — delegate to the current state.
    public void insertCard(Card card) { current.insertCard(card); }
    public void enterPin(String pin) { current.enterPin(pin); }
    public void performTransaction(Transaction transaction) { current.performTransaction(transaction); }
    public void ejectCard() { current.ejectCard(); }

    // Context helpers used by the states.
    public void setState(ATMState state) { this.current = state; }
    public BankService getBank() { return bank; }
    public CashDispenser getDispenser() { return dispenser; }
    public void setCurrentCard(Card card) { this.currentCard = card; }
    public Card getCurrentCard() { return currentCard; }
    public void setCurrentAccount(Account account) { this.currentAccount = account; }
    public Account getCurrentAccount() { return currentAccount; }
    public int getPinAttempts() { return pinAttempts; }
    public void incrementPinAttempts() { this.pinAttempts++; }
    public void resetSession() {
        this.currentCard = null;
        this.currentAccount = null;
        this.pinAttempts = 0;
    }

    public ATMState getIdleState() { return idleState; }
    public ATMState getHasCardState() { return hasCardState; }
    public ATMState getAuthenticatedState() { return authenticatedState; }
    public String currentStateName() { return current.name(); }
}
