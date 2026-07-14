package chapter30;

/**
 * Concrete Strategy — cheap for the first week, then escalates. Shows that a
 * new fine policy is just a new class, with no change to the return workflow.
 */
public class TieredFineStrategy implements FineStrategy {
    private final double lowRate;
    private final double highRate;
    private final int threshold;

    public TieredFineStrategy(double lowRate, double highRate, int threshold) {
        this.lowRate = lowRate;
        this.highRate = highRate;
        this.threshold = threshold;
    }

    @Override
    public double calculateFine(int overdueDays) {
        if (overdueDays <= threshold) {
            return overdueDays * lowRate;
        }
        return threshold * lowRate + (overdueDays - threshold) * highRate;
    }
}
