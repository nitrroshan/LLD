package chapter40;

/**
 * Free delivery above a subtotal threshold, otherwise a flat fee.
 */
public class FreeAboveThresholdPricingStrategy implements DeliveryPricingStrategy {
    private final double threshold;
    private final double flatFee;

    public FreeAboveThresholdPricingStrategy(double threshold, double flatFee) {
        this.threshold = threshold;
        this.flatFee = flatFee;
    }

    @Override
    public double calculateFee(double distanceKm, double subtotal) {
        return subtotal >= threshold ? 0.0 : flatFee;
    }
}
