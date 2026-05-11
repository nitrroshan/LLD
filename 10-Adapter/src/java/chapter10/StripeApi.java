package chapter10;

/**
 * Third-party Stripe API — we don't control this code.
 * Different method names, amount in cents (int), returns its own result type.
 */
public class StripeApi {
    public StripeResult createCharge(int cents, String currency, String token) {
        System.out.println("  [Stripe] Charging " + cents + " cents (" + currency + ") token=" + token);
        return new StripeResult(true, "ch_" + System.nanoTime());
    }

    public StripeResult createRefund(String chargeId) {
        System.out.println("  [Stripe] Refunding charge " + chargeId);
        return new StripeResult(true, "re_" + System.nanoTime());
    }

    public static class StripeResult {
        private final boolean success;
        private final String id;

        public StripeResult(boolean success, String id) {
            this.success = success;
            this.id = id;
        }

        public boolean isSuccess() { return success; }
        public String getId() { return id; }
    }
}
