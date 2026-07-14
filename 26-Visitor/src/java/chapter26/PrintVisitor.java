package chapter26;

/**
 * Concrete Visitor — renders the expression as infix text. Adding this
 * operation required NO change to any element class.
 */
public class PrintVisitor implements Visitor {
    private String result = "";

    public String getResult() {
        return result;
    }

    @Override
    public void visitNumber(NumberExpr number) {
        result = String.format("%.0f", number.getValue());
    }

    @Override
    public void visitAddition(Addition addition) {
        addition.getLeft().accept(this);
        String left = result;
        addition.getRight().accept(this);
        String right = result;
        result = "(" + left + " + " + right + ")";
    }

    @Override
    public void visitMultiplication(Multiplication multiplication) {
        multiplication.getLeft().accept(this);
        String left = result;
        multiplication.getRight().accept(this);
        String right = result;
        result = "(" + left + " * " + right + ")";
    }
}
