package chapter22;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Strategy Pattern Demo ===\n");

        ShoppingCart cart = new ShoppingCart();
        cart.addItem("Keyboard", 49.99);
        cart.addItem("Mouse", 25.50);

        // Choose a strategy at runtime
        System.out.println("\nCheckout with credit card:");
        cart.setPaymentStrategy(new CreditCardStrategy("1234567812345678"));
        cart.checkout();

        // A new order, different strategy — no change to ShoppingCart
        cart.addItem("Monitor", 199.00);
        System.out.println("\nCheckout with PayPal:");
        cart.setPaymentStrategy(new PayPalStrategy("shopper@example.com"));
        cart.checkout();

        // Crypto strategy
        cart.addItem("Webcam", 60.00);
        System.out.println("\nCheckout with crypto:");
        cart.setPaymentStrategy(new CryptoStrategy("0xABCD...1234"));
        cart.checkout();

        // A strategy can also be a lambda — no dedicated class needed
        cart.addItem("Cable", 9.99);
        System.out.println("\nCheckout with a lambda strategy (Apple Pay):");
        cart.setPaymentStrategy(amount ->
            System.out.printf("  Paid $%.2f with Apple Pay%n", amount));
        cart.checkout();
    }
}
