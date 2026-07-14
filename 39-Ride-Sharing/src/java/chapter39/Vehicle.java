package chapter39;

/**
 * A vehicle of a given type with a plate. Built by the VehicleFactory.
 */
public class Vehicle {
    private final VehicleType type;
    private final String plate;

    public Vehicle(VehicleType type, String plate) {
        this.type = type;
        this.plate = plate;
    }

    public VehicleType type() { return type; }
    public String plate() { return plate; }
    public double ratePerKm() { return type.ratePerKm(); }
}
