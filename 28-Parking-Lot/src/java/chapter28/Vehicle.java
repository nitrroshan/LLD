package chapter28;

/**
 * Abstract vehicle. Concrete subclasses declare their type (and thus size).
 */
public abstract class Vehicle {
    private final String licensePlate;

    protected Vehicle(String licensePlate) {
        this.licensePlate = licensePlate;
    }

    public String getLicensePlate() {
        return licensePlate;
    }

    public abstract VehicleType getType();
}
