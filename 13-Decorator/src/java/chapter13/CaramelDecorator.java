package chapter13;

public class CaramelDecorator extends CoffeeDecorator {

    public CaramelDecorator(Coffee wrapped) {
        super(wrapped);
    }

    @Override
    public String getDescription() {
        return wrapped.getDescription() + ", Caramel";
    }

    @Override
    public double getCost() {
        return wrapped.getCost() + 0.60;
    }
}
