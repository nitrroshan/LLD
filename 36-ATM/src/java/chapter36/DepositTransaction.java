package chapter36;

/**
 * Command — deposit cash into the account.
 */
public class DepositTransaction implements Transaction {
    private final Account account;
    private final int amount;

    public DepositTransaction(Account account, int amount) {
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void execute() {
        account.credit(amount);
        System.out.println("  Deposited $" + amount + ". New balance: $" + account.getBalance());
    }

    @Override
    public String description() {
        return "Deposit $" + amount;
    }
}
