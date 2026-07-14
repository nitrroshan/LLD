package chapter37;

/**
 * Seasonal pricing — applies a peak-season multiplier over the base rate.
 */
public class SeasonalPricingStrategy implements PricingStrategy {
    private final double multiplier;

    public SeasonalPricingStrategy(double multiplier) {
        this.multiplier = multiplier;
    }

    @Override
    public double calculatePrice(RoomType type, int nights) {
        return type.basePrice() * nights * multiplier;
    }
}
