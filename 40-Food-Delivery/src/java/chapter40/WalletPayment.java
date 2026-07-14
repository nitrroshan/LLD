package chapter40;

public class WalletPayment implements PaymentMethod {
    @Override
    public boolean pay(double amount) {
        System.out.printf("    Paid %.1f by Wallet%n", amount);
        return true;
    }
}
