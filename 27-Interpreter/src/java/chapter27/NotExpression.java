package chapter27;

/**
 * Non-terminal Expression — logical NOT of one sub-expression.
 */
public class NotExpression implements Expression {
    private final Expression expression;

    public NotExpression(Expression expression) {
        this.expression = expression;
    }

    @Override
    public boolean interpret(Context context) {
        return !expression.interpret(context);
    }
}
