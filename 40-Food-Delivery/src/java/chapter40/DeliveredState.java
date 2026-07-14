package chapter40;

/** Terminal — the order was delivered. */
public class DeliveredState implements OrderState {
    private static final DeliveredState INSTANCE = new DeliveredState();
    private DeliveredState() {}
    public static DeliveredState instance() { return INSTANCE; }

    @Override public void confirm(Order order) { rejected(); }
    @Override public void prepare(Order order) { rejected(); }
    @Override public void dispatch(Order order, DeliveryAgent agent) { rejected(); }
    @Override public void deliver(Order order) { rejected(); }
    @Override public void cancel(Order order) { rejected(); }
    @Override public String name() { return "DELIVERED"; }

    private void rejected() { System.out.println("    Order is already delivered"); }
}
