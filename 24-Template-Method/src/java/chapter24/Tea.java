package chapter24;

/**
 * Concrete Class — fills in the varying steps for tea.
 */
public class Tea extends CaffeineBeverage {
    @Override
    protected void brew() {
        System.out.println("  Steeping the tea");
    }

    @Override
    protected void addCondiments() {
        System.out.println("  Adding lemon");
    }
}
