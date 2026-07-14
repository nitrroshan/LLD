package chapter37;

/**
 * The room categories, each with a nightly base price.
 */
public enum RoomType {
    SINGLE(100),
    DOUBLE(150),
    SUITE(300),
    DELUXE(500);

    private final int basePrice;

    RoomType(int basePrice) {
        this.basePrice = basePrice;
    }

    public int basePrice() {
        return basePrice;
    }
}
