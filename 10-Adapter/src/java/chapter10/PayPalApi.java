package chapter10;

/**
 * Third-party PayPal API — we don't control this code.
 * Different method names, amount as float, returns its own response type.
 */
public class PayPalApi {
    public PayPalResponse sendPayment(float amount, String currencyCode) {
        System.out.println("  [PayPal] Sending " + amount + " " + currencyCode);
        return new PayPalResponse(0, "PAY-" + System.nanoTime());
    }

    public PayPalResponse reversePayment(String paymentId) {
        System.out.println("  [PayPal] Reversing payment " + paymentId);
        return new PayPalResponse(0, "REV-" + System.nanoTime());
    }

    public static class PayPalResponse {
        private final int statusCode;  // 0 = success, non-zero = error
        private final String paymentId;

        public PayPalResponse(int statusCode, String paymentId) {
            this.statusCode = statusCode;
            this.paymentId = paymentId;
        }

        public int getStatusCode() { return statusCode; }
        public String getPaymentId() { return paymentId; }
    }
}
