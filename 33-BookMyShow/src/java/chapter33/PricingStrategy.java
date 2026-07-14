package chapter33;

/**
 * Strategy — prices a seat for a show.
 */
public interface PricingStrategy {
    double calculatePrice(Seat seat, Show show);
}
