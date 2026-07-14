package chapter40;

/**
 * Strategy — computes the delivery fee from distance and order subtotal.
 */
public interface DeliveryPricingStrategy {
    double calculateFee(double distanceKm, double subtotal);
}
