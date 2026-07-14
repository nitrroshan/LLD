package chapter27;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Interpreter Pattern Demo ===\n");

        // Build the rule tree for: (A OR B) AND (NOT C)
        Expression rule = new AndExpression(
            new OrExpression(new Variable("A"), new Variable("B")),
            new NotExpression(new Variable("C"))
        );

        System.out.println("Rule: (A OR B) AND (NOT C)\n");

        // Evaluate against different contexts — the SAME tree, different inputs
        evaluate(rule, true, false, false);   // (T or F) and (not F) = T
        evaluate(rule, false, false, false);  // (F or F) and (not F) = F
        evaluate(rule, true, true, true);     // (T or T) and (not T) = F
    }

    static void evaluate(Expression rule, boolean a, boolean b, boolean c) {
        Context context = new Context();
        context.set("A", a);
        context.set("B", b);
        context.set("C", c);
        System.out.printf("  A=%b, B=%b, C=%b -> %b%n", a, b, c, rule.interpret(context));
    }
}
