package chapter40;

public class UpiPayment implements PaymentMethod {
    @Override
    public boolean pay(double amount) {
        System.out.printf("    Paid %.1f by UPI%n", amount);
        return true;
    }
}
