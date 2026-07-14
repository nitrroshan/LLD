package chapter27;

/**
 * Terminal Expression — a variable that looks up its value in the context.
 */
public class Variable implements Expression {
    private final String name;

    public Variable(String name) {
        this.name = name;
    }

    @Override
    public boolean interpret(Context context) {
        return context.get(name);
    }
}
