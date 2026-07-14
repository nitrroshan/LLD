package chapter13;

public class MilkDecorator extends CoffeeDecorator {

    public MilkDecorator(Coffee wrapped) {
        super(wrapped);
    }

    @Override
    public String getDescription() {
        return wrapped.getDescription() + ", Milk";
    }

    @Override
    public double getCost() {
        return wrapped.getCost() + 0.50;
    }
}
