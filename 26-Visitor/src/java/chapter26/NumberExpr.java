package chapter26;

/**
 * Concrete Element — a literal number. (Named NumberExpr to avoid clashing
 * with java.lang.Number.)
 */
public class NumberExpr implements Expression {
    private final double value;

    public NumberExpr(double value) {
        this.value = value;
    }

    public double getValue() {
        return value;
    }

    @Override
    public void accept(Visitor visitor) {
        visitor.visitNumber(this);
    }
}
