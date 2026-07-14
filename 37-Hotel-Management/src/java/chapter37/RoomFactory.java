package chapter37;

/**
 * Factory — builds a room with type-specific amenities from a RoomType, so a
 * caller can't create (say) a Suite without its amenities.
 */
public class RoomFactory {
    public static Room create(RoomType type, String number) {
        String amenities = switch (type) {
            case SINGLE -> "WiFi, TV";
            case DOUBLE -> "WiFi, TV, Minibar";
            case SUITE  -> "WiFi, TV, Minibar, Jacuzzi";
            case DELUXE -> "WiFi, TV, Minibar, Jacuzzi, Balcony";
        };
        return new Room(number, type, amenities);
    }
}
