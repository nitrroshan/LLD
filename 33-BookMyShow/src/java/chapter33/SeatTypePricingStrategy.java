package chapter33;

import java.util.EnumMap;
import java.util.Map;

/**
 * Concrete Strategy — base price by seat type (the pricing tiers).
 */
public class SeatTypePricingStrategy implements PricingStrategy {
    private final Map<SeatType, Double> basePrices = new EnumMap<>(SeatType.class);

    public SeatTypePricingStrategy() {
        basePrices.put(SeatType.REGULAR, 10.0);
        basePrices.put(SeatType.PREMIUM, 15.0);
        basePrices.put(SeatType.RECLINER, 25.0);
    }

    @Override
    public double calculatePrice(Seat seat, Show show) {
        return basePrices.getOrDefault(seat.getType(), 10.0);
    }
}
