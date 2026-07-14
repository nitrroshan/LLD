package chapter28;

/**
 * Abstract parking spot. Fit logic is size-based: a spot holds a vehicle when
 * it is free and its size is at least the vehicle's size.
 */
public abstract class ParkingSpot {
    private final String id;
    private final SpotType type;
    private Vehicle parkedVehicle;

    protected ParkingSpot(String id, SpotType type) {
        this.id = id;
        this.type = type;
    }

    public String getId() {
        return id;
    }

    public SpotType getType() {
        return type;
    }

    public boolean isAvailable() {
        return parkedVehicle == null;
    }

    public boolean canFit(Vehicle vehicle) {
        return isAvailable() && type.getSize() >= vehicle.getType().getSize();
    }

    public void park(Vehicle vehicle) {
        if (!canFit(vehicle)) {
            throw new IllegalStateException("Spot " + id + " cannot fit " + vehicle.getLicensePlate());
        }
        this.parkedVehicle = vehicle;
    }

    public void vacate() {
        this.parkedVehicle = null;
    }

    public Vehicle getParkedVehicle() {
        return parkedVehicle;
    }
}
