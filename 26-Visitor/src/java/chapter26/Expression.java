package chapter26;

/**
 * Element — declares accept(visitor). Concrete elements implement it by
 * calling the visitor's method for their own type (double dispatch).
 */
public interface Expression {
    void accept(Visitor visitor);
}
