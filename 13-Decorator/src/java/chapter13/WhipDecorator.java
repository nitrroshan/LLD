package chapter13;

public class WhipDecorator extends CoffeeDecorator {

    public WhipDecorator(Coffee wrapped) {
        super(wrapped);
    }

    @Override
    public String getDescription() {
        return wrapped.getDescription() + ", Whip";
    }

    @Override
    public double getCost() {
        return wrapped.getCost() + 0.70;
    }
}
