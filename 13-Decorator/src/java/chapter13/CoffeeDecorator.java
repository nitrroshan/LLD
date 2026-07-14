package chapter13;

/**
 * Abstract Decorator — implements Coffee AND wraps a Coffee.
 * Subclasses add specific behavior.
 */
public abstract class CoffeeDecorator implements Coffee {
    protected final Coffee wrapped;

    protected CoffeeDecorator(Coffee wrapped) {
        this.wrapped = wrapped;
    }
}
