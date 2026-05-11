package chapter10;

/**
 * Adapter: Translates PaymentProcessor calls → PayPalApi calls.
 *
 * Translation:
 *   processPayment(double, String) → sendPayment(float, String)
 *   refund(String)                 → reversePayment(String)
 *   boolean return                 ← statusCode == 0
 */
public class PayPalAdapter implements PaymentProcessor {
    private final PayPalApi paypal;

    public PayPalAdapter(PayPalApi paypal) {
        this.paypal = paypal;
    }

    @Override
    public boolean processPayment(double amount, String currency) {
        // Translate: double → float
        PayPalApi.PayPalResponse response = paypal.sendPayment((float) amount, currency);
        return response.getStatusCode() == 0;
    }

    @Override
    public boolean refund(String transactionId) {
        PayPalApi.PayPalResponse response = paypal.reversePayment(transactionId);
        return response.getStatusCode() == 0;
    }
}
