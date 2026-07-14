package chapter37;

/**
 * Strategy — prices a stay given the room type and number of nights.
 */
public interface PricingStrategy {
    double calculatePrice(RoomType type, int nights);
}
