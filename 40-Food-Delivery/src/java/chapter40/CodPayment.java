package chapter40;

public class CodPayment implements PaymentMethod {
    @Override
    public boolean pay(double amount) {
        System.out.printf("    Cash on delivery: %.1f due%n", amount);
        return true;
    }
}
