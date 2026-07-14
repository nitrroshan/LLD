package chapter36;

/**
 * Command — read the account balance.
 */
public class BalanceInquiryTransaction implements Transaction {
    private final Account account;

    public BalanceInquiryTransaction(Account account) {
        this.account = account;
    }

    @Override
    public void execute() {
        System.out.println("  Balance: $" + account.getBalance());
    }

    @Override
    public String description() {
        return "Balance inquiry";
    }
}
