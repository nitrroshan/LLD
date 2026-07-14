package chapter26;

/**
 * Concrete Visitor — computes the numeric value of the expression. It holds a
 * result field; binary nodes recursively visit their children and combine
 * their results.
 */
public class EvaluateVisitor implements Visitor {
    private double result;

    public double getResult() {
        return result;
    }

    @Override
    public void visitNumber(NumberExpr number) {
        result = number.getValue();
    }

    @Override
    public void visitAddition(Addition addition) {
        addition.getLeft().accept(this);
        double left = result;
        addition.getRight().accept(this);
        double right = result;
        result = left + right;
    }

    @Override
    public void visitMultiplication(Multiplication multiplication) {
        multiplication.getLeft().accept(this);
        double left = result;
        multiplication.getRight().accept(this);
        double right = result;
        result = left * right;
    }
}
