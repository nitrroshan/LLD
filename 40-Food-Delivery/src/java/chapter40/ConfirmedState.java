package chapter40;

/** The restaurant confirmed the order; it can start preparing or be cancelled. */
public class ConfirmedState implements OrderState {
    private static final ConfirmedState INSTANCE = new ConfirmedState();
    private ConfirmedState() {}
    public static ConfirmedState instance() { return INSTANCE; }

    @Override public void confirm(Order order) { System.out.println("    Order already confirmed"); }

    @Override
    public void prepare(Order order) {
        order.setState(PreparingState.instance());
        order.notifyObservers("PREPARING");
    }

    @Override public void dispatch(Order order, DeliveryAgent agent) { System.out.println("    Order not ready"); }
    @Override public void deliver(Order order) { System.out.println("    Order not out for delivery"); }

    @Override
    public void cancel(Order order) {
        order.setState(CancelledState.instance());
        order.notifyObservers("CANCELLED");
    }

    @Override public String name() { return "CONFIRMED"; }
}
