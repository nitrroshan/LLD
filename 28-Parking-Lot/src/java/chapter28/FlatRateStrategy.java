package chapter28;

/**
 * Concrete Strategy — one flat fee regardless of duration.
 */
public class FlatRateStrategy implements PricingStrategy {
    private final double flatFee;

    public FlatRateStrategy(double flatFee) {
        this.flatFee = flatFee;
    }

    @Override
    public double calculatePrice(Ticket ticket, long exitTime) {
        return flatFee;
    }
}
