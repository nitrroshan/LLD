package chapter28;

/**
 * Factory Method — creates a Vehicle from a VehicleType token, so callers
 * (entrance panels, sensors) don't depend on concrete vehicle classes.
 */
public class VehicleFactory {
    public static Vehicle create(VehicleType type, String licensePlate) {
        switch (type) {
            case MOTORCYCLE:
                return new Motorcycle(licensePlate);
            case CAR:
                return new Car(licensePlate);
            case TRUCK:
                return new Truck(licensePlate);
            default:
                throw new IllegalArgumentException("Unknown vehicle type: " + type);
        }
    }
}
