package chapter27;

/**
 * AbstractExpression — every grammar rule implements interpret(context).
 */
public interface Expression {
    boolean interpret(Context context);
}
