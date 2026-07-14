package chapter40;

/**
 * Distance-based delivery fee: a flat base plus a per-km charge.
 */
public class DistanceBasedPricingStrategy implements DeliveryPricingStrategy {
    private final double base;
    private final double perKm;

    public DistanceBasedPricingStrategy(double base, double perKm) {
        this.base = base;
        this.perKm = perKm;
    }

    @Override
    public double calculateFee(double distanceKm, double subtotal) {
        return base + perKm * distanceKm;
    }
}
