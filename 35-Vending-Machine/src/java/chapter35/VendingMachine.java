package chapter35;

/**
 * Context — holds inventory, the coin-acceptor chain, the current state, and
 * the transaction data (balance + selection). All user actions delegate to the
 * current state.
 */
public class VendingMachine {
    private final Inventory inventory;
    private final CoinHandler coinChain;

    private final VendingMachineState idleState;
    private final VendingMachineState awaitingPaymentState;
    private final DispensingState dispensingState;

    private VendingMachineState current;
    private int balance = 0;
    private String selectedCode;

    public VendingMachine(Inventory inventory, CoinHandler coinChain) {
        this.inventory = inventory;
        this.coinChain = coinChain;
        this.idleState = new IdleState(this);
        this.awaitingPaymentState = new AwaitingPaymentState(this);
        this.dispensingState = new DispensingState(this);
        this.current = idleState;
    }

    // User actions — delegate to the current state.
    public void selectProduct(String code) { current.selectProduct(code); }
    public void insertCoin(Coin coin) { current.insertCoin(coin); }
    public void payWith(PaymentStrategy strategy) { current.payWith(strategy); }
    public void cancel() { current.cancel(); }

    // Context helpers used by the states.
    public void setState(VendingMachineState state) { this.current = state; }
    public Inventory getInventory() { return inventory; }
    public CoinHandler getCoinChain() { return coinChain; }
    public int getBalance() { return balance; }
    public void addBalance(int cents) { this.balance += cents; }
    public void reset() { this.balance = 0; this.selectedCode = null; }
    public void setSelectedCode(String code) { this.selectedCode = code; }
    public Product getSelectedProduct() { return inventory.getProduct(selectedCode); }

    public VendingMachineState getIdleState() { return idleState; }
    public VendingMachineState getAwaitingPaymentState() { return awaitingPaymentState; }
    public DispensingState getDispensingState() { return dispensingState; }
    public String currentStateName() { return current.name(); }
}
