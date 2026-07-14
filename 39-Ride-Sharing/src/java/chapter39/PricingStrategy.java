package chapter39;

/**
 * Strategy — computes the fare for a distance and vehicle.
 */
public interface PricingStrategy {
    double calculateFare(double distanceKm, Vehicle vehicle);
}
