package chapter45;

/**
 * The record produced by a checkout — the value a test asserts against.
 */
public class Receipt {
    public final double total;
    public final long timestamp;
    public final boolean paid;

    public Receipt(double total, long timestamp, boolean paid) {
        this.total = total;
        this.timestamp = timestamp;
        this.paid = paid;
    }
}
