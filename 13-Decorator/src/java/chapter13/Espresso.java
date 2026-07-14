package chapter13;

/**
 * Concrete Component — base espresso coffee.
 */
public class Espresso implements Coffee {
    @Override
    public String getDescription() {
        return "Espresso";
    }

    @Override
    public double getCost() {
        return 2.00;
    }
}
