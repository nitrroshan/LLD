package chapter37;

/**
 * Base pricing — the plain nightly rate times the number of nights.
 */
public class BasePricingStrategy implements PricingStrategy {
    @Override
    public double calculatePrice(RoomType type, int nights) {
        return type.basePrice() * nights;
    }
}
