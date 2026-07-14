package chapter33;

/**
 * Processes a charge. Minimal stand-in for a real payment gateway.
 */
public class Payment {
    private final double amount;
    private boolean success;

    public Payment(double amount) {
        this.amount = amount;
    }

    public boolean process() {
        // A real gateway could decline; here it always succeeds.
        success = true;
        System.out.printf("    Charged $%.2f%n", amount);
        return success;
    }

    public double getAmount() { return amount; }
    public boolean isSuccess() { return success; }
}
