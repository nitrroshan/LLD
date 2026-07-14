package chapter40;

/** The order was just placed; it can be confirmed or cancelled. */
public class PlacedState implements OrderState {
    private static final PlacedState INSTANCE = new PlacedState();
    private PlacedState() {}
    public static PlacedState instance() { return INSTANCE; }

    @Override
    public void confirm(Order order) {
        order.setState(ConfirmedState.instance());
        order.notifyObservers("CONFIRMED");
    }

    @Override public void prepare(Order order) { System.out.println("    Order not confirmed yet"); }
    @Override public void dispatch(Order order, DeliveryAgent agent) { System.out.println("    Order not ready"); }
    @Override public void deliver(Order order) { System.out.println("    Order not out for delivery"); }

    @Override
    public void cancel(Order order) {
        order.setState(CancelledState.instance());
        order.notifyObservers("CANCELLED");
    }

    @Override public String name() { return "PLACED"; }
}
