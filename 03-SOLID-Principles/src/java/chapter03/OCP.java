package chapter03;

/**
 * OCP — Open/Closed Principle
 *
 * BAD:  DiscountCalculator uses if/else chain — adding a new customer type requires editing.
 * GOOD: Each discount strategy implements an interface — adding new types = adding new classes.
 */
public class OCP {

    // ===================== BAD =====================
    static class DiscountCalculatorBad {
        double calculate(String customerType, double amount) {
            if (customerType.equals("Regular")) {
                return amount * 0.05;
            } else if (customerType.equals("Premium")) {
                return amount * 0.10;
            } else if (customerType.equals("VIP")) {
                return amount * 0.20;
            }
            // Adding "Employee" discount? Must edit this method!
            return 0;
        }
    }

    // ===================== GOOD =====================
    interface DiscountStrategy {
        double calculate(double amount);
    }

    static class RegularDiscount implements DiscountStrategy {
        public double calculate(double amount) { return amount * 0.05; }
    }

    static class PremiumDiscount implements DiscountStrategy {
        public double calculate(double amount) { return amount * 0.10; }
    }

    static class VIPDiscount implements DiscountStrategy {
        public double calculate(double amount) { return amount * 0.20; }
    }

    // Adding Employee discount? Just add a new class — nothing else changes!
    static class EmployeeDiscount implements DiscountStrategy {
        public double calculate(double amount) { return amount * 0.30; }
    }

    static class DiscountCalculator {
        double calculate(DiscountStrategy strategy, double amount) {
            return strategy.calculate(amount);
        }
    }

    // ===================== DEMO =====================
    public static void main(String[] args) {
        double amount = 1000;

        System.out.println("=== BAD (if/else chain — closed for extension) ===");
        DiscountCalculatorBad bad = new DiscountCalculatorBad();
        System.out.println("Regular: $" + bad.calculate("Regular", amount));
        System.out.println("Premium: $" + bad.calculate("Premium", amount));

        System.out.println("\n=== GOOD (strategy interface — open for extension) ===");
        DiscountCalculator calc = new DiscountCalculator();
        System.out.println("Regular:  $" + calc.calculate(new RegularDiscount(), amount));
        System.out.println("Premium:  $" + calc.calculate(new PremiumDiscount(), amount));
        System.out.println("VIP:      $" + calc.calculate(new VIPDiscount(), amount));
        System.out.println("Employee: $" + calc.calculate(new EmployeeDiscount(), amount));
    }
}
