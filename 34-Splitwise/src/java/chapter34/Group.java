package chapter34;

import java.util.ArrayList;
import java.util.List;

/**
 * Mediator — members interact only through the group. Adding an expense routes
 * here: the group computes splits (Strategy), updates the shared BalanceSheet,
 * and notifies observers. Members never settle with each other directly.
 */
public class Group {
    private final String name;
    private final List<User> members = new ArrayList<>();
    private final List<Expense> expenses = new ArrayList<>();
    private final BalanceSheet balanceSheet = new BalanceSheet();
    private final List<BalanceObserver> observers = new ArrayList<>();

    public Group(String name) {
        this.name = name;
    }

    public void addMember(User user) {
        members.add(user);
    }

    public void addObserver(BalanceObserver observer) {
        observers.add(observer);
    }

    public void addExpense(String description, double amount, User paidBy,
                           List<User> participants, SplitStrategy strategy) {
        List<Split> splits = strategy.calculateSplits(amount, participants);
        expenses.add(new Expense(description, amount, paidBy, splits));
        System.out.printf("  %s paid $%.2f for '%s'%n", paidBy.getName(), amount, description);

        for (Split split : splits) {
            if (!split.getUser().equals(paidBy)) {
                balanceSheet.addDebt(split.getUser(), paidBy, split.getAmount());
                notifyBalance(split.getUser(), paidBy, split.getAmount());
            }
        }
    }

    public void showBalances() {
        System.out.println("  Balances for group '" + name + "':");
        balanceSheet.show();
    }

    public List<Settlement> simplify() {
        return balanceSheet.simplify(members);
    }

    private void notifyBalance(User debtor, User creditor, double amount) {
        for (BalanceObserver observer : observers) {
            observer.onBalanceUpdated(debtor, creditor, amount);
        }
    }
}
