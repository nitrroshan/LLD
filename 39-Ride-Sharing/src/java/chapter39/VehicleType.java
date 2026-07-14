package chapter39;

/**
 * The vehicle categories, each with a per-km rate.
 */
public enum VehicleType {
    BIKE(5),
    AUTO(8),
    SEDAN(12),
    SUV(18);

    private final double ratePerKm;

    VehicleType(double ratePerKm) {
        this.ratePerKm = ratePerKm;
    }

    public double ratePerKm() {
        return ratePerKm;
    }
}
