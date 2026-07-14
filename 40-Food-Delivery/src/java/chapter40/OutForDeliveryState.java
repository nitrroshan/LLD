package chapter40;

/** An agent is delivering the order; it can only be delivered. */
public class OutForDeliveryState implements OrderState {
    private static final OutForDeliveryState INSTANCE = new OutForDeliveryState();
    private OutForDeliveryState() {}
    public static OutForDeliveryState instance() { return INSTANCE; }

    @Override public void confirm(Order order) { System.out.println("    Order already out for delivery"); }
    @Override public void prepare(Order order) { System.out.println("    Order already out for delivery"); }
    @Override public void dispatch(Order order, DeliveryAgent agent) { System.out.println("    Order already dispatched"); }

    @Override
    public void deliver(Order order) {
        order.setState(DeliveredState.instance());
        order.notifyObservers("DELIVERED");
    }

    @Override public void cancel(Order order) { System.out.println("    Cannot cancel a delivery in progress"); }

    @Override public String name() { return "OUT_FOR_DELIVERY"; }
}
