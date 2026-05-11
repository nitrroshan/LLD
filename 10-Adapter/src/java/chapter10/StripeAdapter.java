package chapter10;

/**
 * Adapter: Translates PaymentProcessor calls → StripeApi calls.
 *
 * Translation:
 *   processPayment(double, String) → createCharge(int cents, String, String token)
 *   refund(String)                 → createRefund(String)
 *   boolean return                 ← StripeResult.isSuccess()
 */
public class StripeAdapter implements PaymentProcessor {
    private final StripeApi stripe;
    private final String apiToken;

    public StripeAdapter(StripeApi stripe, String apiToken) {
        this.stripe = stripe;
        this.apiToken = apiToken;
    }

    @Override
    public boolean processPayment(double amount, String currency) {
        // Translate: double dollars → int cents
        int cents = (int) Math.round(amount * 100);
        StripeApi.StripeResult result = stripe.createCharge(cents, currency, apiToken);
        return result.isSuccess();
    }

    @Override
    public boolean refund(String transactionId) {
        StripeApi.StripeResult result = stripe.createRefund(transactionId);
        return result.isSuccess();
    }
}
