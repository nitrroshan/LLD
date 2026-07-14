package chapter24;

/**
 * Concrete Class — black coffee overrides the hook to skip condiments.
 */
public class BlackCoffee extends CaffeineBeverage {
    @Override
    protected void brew() {
        System.out.println("  Dripping coffee through filter");
    }

    @Override
    protected void addCondiments() {
        // no condiments
    }

    @Override
    protected boolean wantsCondiments() {
        return false;   // hook overridden — the condiment step is skipped
    }
}
