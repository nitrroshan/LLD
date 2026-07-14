package chapter40;

/**
 * Factory — builds a PaymentMethod from a PaymentType. Adding a method is one
 * new class plus one case here; the ordering flow never changes.
 */
public class PaymentFactory {
    public static PaymentMethod create(PaymentType type) {
        return switch (type) {
            case CARD -> new CardPayment();
            case UPI -> new UpiPayment();
            case WALLET -> new WalletPayment();
            case COD -> new CodPayment();
        };
    }
}
