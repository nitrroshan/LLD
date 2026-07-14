package chapter28;

/**
 * Spot sizes, ordered so a larger spot can hold a smaller vehicle.
 */
public enum SpotType {
    SMALL(1),
    MEDIUM(2),
    LARGE(3);

    private final int size;

    SpotType(int size) {
        this.size = size;
    }

    public int getSize() {
        return size;
    }
}
