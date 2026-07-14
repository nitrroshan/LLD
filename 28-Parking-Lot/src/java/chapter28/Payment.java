package chapter28;

/**
 * Processes the computed fee. Kept minimal; a real system would integrate a
 * payment gateway behind this class.
 */
public class Payment {
    private final double amount;
    private boolean completed;

    public Payment(double amount) {
        this.amount = amount;
    }

    public void process() {
        completed = true;
        System.out.printf("  Payment of $%.2f processed%n", amount);
    }

    public double getAmount() {
        return amount;
    }

    public boolean isCompleted() {
        return completed;
    }
}
