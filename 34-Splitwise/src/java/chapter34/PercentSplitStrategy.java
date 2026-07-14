package chapter34;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Concrete Strategy — split by percentage. Validates that percentages sum to 100.
 */
public class PercentSplitStrategy implements SplitStrategy {
    private final Map<String, Double> percentByUserId;

    public PercentSplitStrategy(Map<String, Double> percentByUserId) {
        this.percentByUserId = percentByUserId;
    }

    @Override
    public List<Split> calculateSplits(double total, List<User> participants) {
        double percentSum = 0;
        for (User user : participants) {
            percentSum += percentByUserId.getOrDefault(user.getId(), 0.0);
        }
        if (Math.abs(percentSum - 100.0) > 0.01) {
            throw new IllegalArgumentException("Percentages must sum to 100 (got " + percentSum + ")");
        }
        List<Split> splits = new ArrayList<>();
        for (User user : participants) {
            double percent = percentByUserId.getOrDefault(user.getId(), 0.0);
            double amount = Math.round(total * percent / 100.0 * 100.0) / 100.0;
            splits.add(new Split(user, amount));
        }
        return splits;
    }
}
