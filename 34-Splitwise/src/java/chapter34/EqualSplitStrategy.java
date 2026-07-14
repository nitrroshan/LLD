package chapter34;

import java.util.ArrayList;
import java.util.List;

/**
 * Concrete Strategy — divide the total equally, giving any rounding remainder
 * to the first participant so the shares sum exactly to the total.
 */
public class EqualSplitStrategy implements SplitStrategy {
    @Override
    public List<Split> calculateSplits(double total, List<User> participants) {
        int n = participants.size();
        double each = Math.round((total / n) * 100.0) / 100.0;
        List<Split> splits = new ArrayList<>();
        double assigned = 0;
        for (int i = 0; i < n; i++) {
            double share = (i == 0) ? total - each * (n - 1) : each;
            splits.add(new Split(participants.get(i), round(share)));
            assigned += share;
        }
        return splits;
    }

    private double round(double v) {
        return Math.round(v * 100.0) / 100.0;
    }
}
