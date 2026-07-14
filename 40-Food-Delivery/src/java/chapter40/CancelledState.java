package chapter40;

/** Terminal — the order was cancelled. */
public class CancelledState implements OrderState {
    private static final CancelledState INSTANCE = new CancelledState();
    private CancelledState() {}
    public static CancelledState instance() { return INSTANCE; }

    @Override public void confirm(Order order) { rejected(); }
    @Override public void prepare(Order order) { rejected(); }
    @Override public void dispatch(Order order, DeliveryAgent agent) { rejected(); }
    @Override public void deliver(Order order) { rejected(); }
    @Override public void cancel(Order order) { rejected(); }
    @Override public String name() { return "CANCELLED"; }

    private void rejected() { System.out.println("    Order is already cancelled"); }
}
