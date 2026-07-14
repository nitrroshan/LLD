package chapter17;

/**
 * The request that travels along the chain of handlers.
 */
public class PurchaseRequest {
    private final double amount;
    private final String purpose;

    public PurchaseRequest(double amount, String purpose) {
        this.amount = amount;
        this.purpose = purpose;
    }

    public double getAmount() {
        return amount;
    }

    public String getPurpose() {
        return purpose;
    }
}
