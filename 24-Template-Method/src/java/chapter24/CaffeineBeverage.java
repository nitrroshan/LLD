package chapter24;

/**
 * Abstract Class — defines the algorithm skeleton in the template method
 * prepareRecipe(). Concrete steps are shared; abstract steps vary per subclass;
 * wantsCondiments() is a hook subclasses may override.
 */
public abstract class CaffeineBeverage {

    /** Template method — the fixed skeleton. final so it can't be overridden. */
    public final void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        if (wantsCondiments()) {
            addCondiments();
        }
    }

    // Invariant steps — shared by all beverages.
    private void boilWater() {
        System.out.println("  Boiling water");
    }

    private void pourInCup() {
        System.out.println("  Pouring into cup");
    }

    // Varying steps — each subclass must supply these.
    protected abstract void brew();
    protected abstract void addCondiments();

    // Hook — default behavior a subclass may override.
    protected boolean wantsCondiments() {
        return true;
    }
}
