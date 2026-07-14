package chapter27;

/**
 * Terminal Expression — a literal true/false constant.
 */
public class Constant implements Expression {
    private final boolean value;

    public Constant(boolean value) {
        this.value = value;
    }

    @Override
    public boolean interpret(Context context) {
        return value;
    }
}
