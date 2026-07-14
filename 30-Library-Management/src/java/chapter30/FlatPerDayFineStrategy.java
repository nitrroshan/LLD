package chapter30;

/**
 * Concrete Strategy — a flat charge per overdue day.
 */
public class FlatPerDayFineStrategy implements FineStrategy {
    private final double ratePerDay;

    public FlatPerDayFineStrategy(double ratePerDay) {
        this.ratePerDay = ratePerDay;
    }

    @Override
    public double calculateFine(int overdueDays) {
        return overdueDays * ratePerDay;
    }
}
