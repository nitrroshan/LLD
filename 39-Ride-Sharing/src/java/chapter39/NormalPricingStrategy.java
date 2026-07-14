package chapter39;

/**
 * Normal pricing — distance times the vehicle's per-km rate.
 */
public class NormalPricingStrategy implements PricingStrategy {
    @Override
    public double calculateFare(double distanceKm, Vehicle vehicle) {
        return distanceKm * vehicle.ratePerKm();
    }
}
