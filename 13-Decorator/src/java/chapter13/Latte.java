package chapter13;

/**
 * Concrete Component — base latte coffee.
 */
public class Latte implements Coffee {
    @Override
    public String getDescription() {
        return "Latte";
    }

    @Override
    public double getCost() {
        return 3.00;
    }
}
