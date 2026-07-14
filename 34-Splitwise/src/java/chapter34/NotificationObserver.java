package chapter34;

/**
 * Concrete Observer — prints a notification on each balance update.
 */
public class NotificationObserver implements BalanceObserver {
    @Override
    public void onBalanceUpdated(User debtor, User creditor, double amount) {
        System.out.printf("    [Notify] %s owes %s $%.2f for this expense%n",
                debtor.getName(), creditor.getName(), amount);
    }
}
