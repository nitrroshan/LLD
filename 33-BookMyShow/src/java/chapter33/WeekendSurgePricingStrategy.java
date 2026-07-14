package chapter33;

/**
 * Concrete Strategy — wraps a base pricing strategy and applies a surge
 * multiplier (e.g., weekends). Composition over a base strategy, so surge works
 * on top of ANY tier scheme without duplicating prices.
 */
public class WeekendSurgePricingStrategy implements PricingStrategy {
    private final PricingStrategy base;
    private final double multiplier;

    public WeekendSurgePricingStrategy(PricingStrategy base, double multiplier) {
        this.base = base;
        this.multiplier = multiplier;
    }

    @Override
    public double calculatePrice(Seat seat, Show show) {
        return base.calculatePrice(seat, show) * multiplier;
    }
}
