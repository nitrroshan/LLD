package chapter39;

/**
 * Surge pricing — normal fare times a demand multiplier.
 */
public class SurgePricingStrategy implements PricingStrategy {
    private final double multiplier;

    public SurgePricingStrategy(double multiplier) {
        this.multiplier = multiplier;
    }

    @Override
    public double calculateFare(double distanceKm, Vehicle vehicle) {
        return distanceKm * vehicle.ratePerKm() * multiplier;
    }
}
