package chapter30;

/**
 * Strategy — computes the fine for an overdue return.
 */
public interface FineStrategy {
    double calculateFine(int overdueDays);
}
