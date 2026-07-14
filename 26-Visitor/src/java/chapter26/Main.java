package chapter26;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Visitor Pattern Demo ===\n");

        // Build the expression tree: (3 + 4) * 5
        Expression expression = new Multiplication(
            new Addition(new NumberExpr(3), new NumberExpr(4)),
            new NumberExpr(5)
        );

        // Operation 1: print — a visitor
        PrintVisitor printer = new PrintVisitor();
        expression.accept(printer);
        System.out.println("Expression: " + printer.getResult());

        // Operation 2: evaluate — another visitor, same elements
        EvaluateVisitor evaluator = new EvaluateVisitor();
        expression.accept(evaluator);
        System.out.println("Value:      " + evaluator.getResult());

        System.out.println("\nTwo operations, zero changes to the element classes —");
        System.out.println("each visitor added a new operation on its own.");
    }
}
