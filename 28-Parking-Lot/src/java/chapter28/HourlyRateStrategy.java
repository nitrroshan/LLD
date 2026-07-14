package chapter28;

/**
 * Concrete Strategy — charge per hour, scaled by the vehicle's size.
 */
public class HourlyRateStrategy implements PricingStrategy {
    private final double baseRatePerHour;

    public HourlyRateStrategy(double baseRatePerHour) {
        this.baseRatePerHour = baseRatePerHour;
    }

    @Override
    public double calculatePrice(Ticket ticket, long exitTime) {
        long hours = Math.max(1, exitTime - ticket.getEntryTime());
        int sizeMultiplier = ticket.getVehicle().getType().getSize();
        return baseRatePerHour * sizeMultiplier * hours;
    }
}
