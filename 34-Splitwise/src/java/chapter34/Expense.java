package chapter34;

import java.util.List;

/**
 * An amount paid by one user, split among participants.
 */
public class Expense {
    private final String description;
    private final double amount;
    private final User paidBy;
    private final List<Split> splits;

    public Expense(String description, double amount, User paidBy, List<Split> splits) {
        this.description = description;
        this.amount = amount;
        this.paidBy = paidBy;
        this.splits = splits;
    }

    public String getDescription() { return description; }
    public double getAmount() { return amount; }
    public User getPaidBy() { return paidBy; }
    public List<Split> getSplits() { return splits; }
}
