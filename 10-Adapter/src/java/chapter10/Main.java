package chapter10;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Adapter Pattern Demo ===\n");

        // Client code only knows about PaymentProcessor — no idea about Stripe/PayPal APIs
        PaymentProcessor stripe = new StripeAdapter(new StripeApi(), "sk_test_abc123");
        PaymentProcessor paypal = new PayPalAdapter(new PayPalApi());

        // 1. Process payments through the same interface
        System.out.println("--- Process Payments ---");
        processOrder(stripe, 49.99, "USD");
        processOrder(paypal, 29.99, "EUR");
        System.out.println();

        // 2. Refunds through the same interface
        System.out.println("--- Refund Payments ---");
        refundOrder(stripe, "ch_12345");
        refundOrder(paypal, "PAY-67890");
        System.out.println();

        // 3. Swap implementations — client code doesn't change
        System.out.println("--- Swap Implementation ---");
        PaymentProcessor processor = stripe;  // start with Stripe
        processOrder(processor, 99.99, "USD");

        processor = paypal;                   // swap to PayPal — zero code change
        processOrder(processor, 99.99, "USD");
    }

    // Client method — depends only on PaymentProcessor interface
    static void processOrder(PaymentProcessor processor, double amount, String currency) {
        boolean success = processor.processPayment(amount, currency);
        System.out.println("  Payment " + (success ? "succeeded" : "failed") + "\n");
    }

    static void refundOrder(PaymentProcessor processor, String transactionId) {
        boolean success = processor.refund(transactionId);
        System.out.println("  Refund " + (success ? "succeeded" : "failed") + "\n");
    }
}
