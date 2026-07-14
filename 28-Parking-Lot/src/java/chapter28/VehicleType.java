package chapter28;

/**
 * Vehicle types, each with a size that determines the smallest spot it fits.
 */
public enum VehicleType {
    MOTORCYCLE(1),
    CAR(2),
    TRUCK(3);

    private final int size;

    VehicleType(int size) {
        this.size = size;
    }

    public int getSize() {
        return size;
    }
}
