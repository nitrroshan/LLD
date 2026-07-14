package chapter34;

/**
 * Observer — notified when a balance between two users changes.
 */
public interface BalanceObserver {
    void onBalanceUpdated(User debtor, User creditor, double amount);
}
