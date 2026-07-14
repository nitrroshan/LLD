package chapter36;

/**
 * Command — withdraw cash. Checks balance, dispenses notes, THEN debits, so a
 * failed dispense never charges the customer.
 */
public class WithdrawTransaction implements Transaction {
    private final Account account;
    private final CashDispenser dispenser;
    private final int amount;

    public WithdrawTransaction(Account account, CashDispenser dispenser, int amount) {
        this.account = account;
        this.dispenser = dispenser;
        this.amount = amount;
    }

    @Override
    public void execute() {
        if (amount > account.getBalance()) {
            System.out.println("  Insufficient account balance (balance $" + account.getBalance() + ")");
            return;
        }
        if (dispenser.dispense(amount)) {
            account.debit(amount);
            System.out.println("  Withdrew $" + amount + ". New balance: $" + account.getBalance());
        } else {
            System.out.println("  Withdrawal cancelled");
        }
    }

    @Override
    public String description() {
        return "Withdraw $" + amount;
    }
}
