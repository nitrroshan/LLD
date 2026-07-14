package chapter44.after;

/** Factory — maps a CustomerType to its discount Strategy (creation in one place). */
public class DiscountStrategyFactory {
    public static DiscountStrategy forType(CustomerType type) {
        return switch (type) {
            case REGULAR -> new RegularDiscount();
            case PREMIUM -> new PremiumDiscount();
            case VIP -> new VipDiscount();
        };
    }
}
