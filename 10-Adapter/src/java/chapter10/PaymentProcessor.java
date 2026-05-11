package chapter10;

public interface PaymentProcessor {
    boolean processPayment(double amount, String currency);
    boolean refund(String transactionId);
}
