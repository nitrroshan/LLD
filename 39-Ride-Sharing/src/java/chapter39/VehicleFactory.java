package chapter39;

/**
 * Factory — builds a vehicle for a given type (which carries its per-km rate).
 */
public class VehicleFactory {
    public static Vehicle create(VehicleType type, String plate) {
        return new Vehicle(type, plate);
    }
}
