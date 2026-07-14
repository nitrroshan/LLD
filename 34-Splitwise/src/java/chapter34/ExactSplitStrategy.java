package chapter34;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Concrete Strategy — each participant pays an exact, pre-specified amount.
 * Validates that the exact amounts sum to the total.
 */
public class ExactSplitStrategy implements SplitStrategy {
    private final Map<String, Double> exactByUserId;

    public ExactSplitStrategy(Map<String, Double> exactByUserId) {
        this.exactByUserId = exactByUserId;
    }

    @Override
    public List<Split> calculateSplits(double total, List<User> participants) {
        List<Split> splits = new ArrayList<>();
        double sum = 0;
        for (User user : participants) {
            double amount = exactByUserId.getOrDefault(user.getId(), 0.0);
            splits.add(new Split(user, amount));
            sum += amount;
        }
        if (Math.abs(sum - total) > 0.01) {
            throw new IllegalArgumentException("Exact splits (" + sum + ") must sum to the total (" + total + ")");
        }
        return splits;
    }
}
