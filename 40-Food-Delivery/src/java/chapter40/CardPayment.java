package chapter40;

public class CardPayment implements PaymentMethod {
    @Override
    public boolean pay(double amount) {
        System.out.printf("    Paid %.1f by Card%n", amount);
        return true;
    }
}
