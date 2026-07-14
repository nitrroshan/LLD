package chapter22;

/**
 * Context — holds a payment strategy and delegates checkout to it. It never
 * knows which concrete algorithm runs, and the strategy can be swapped at
 * runtime.
 */
public class ShoppingCart {
    private double total = 0;
    private PaymentStrategy strategy;

    public void addItem(String name, double price) {
        total += price;
        System.out.printf("  + %s ($%.2f)%n", name, price);
    }

    public void setPaymentStrategy(PaymentStrategy strategy) {
        this.strategy = strategy;
    }

    public void checkout() {
        if (strategy == null) {
            System.out.println("  No payment method selected!");
            return;
        }
        strategy.pay(total);
        total = 0;
    }
}
