package chapter40;

/**
 * The kitchen is preparing the food. It can be dispatched once ready.
 * Cancellation is no longer allowed — the food is committed.
 */
public class PreparingState implements OrderState {
    private static final PreparingState INSTANCE = new PreparingState();
    private PreparingState() {}
    public static PreparingState instance() { return INSTANCE; }

    @Override public void confirm(Order order) { System.out.println("    Order already preparing"); }
    @Override public void prepare(Order order) { System.out.println("    Order already preparing"); }

    @Override
    public void dispatch(Order order, DeliveryAgent agent) {
        order.setAgent(agent);
        order.setState(OutForDeliveryState.instance());
        order.notifyObservers("OUT_FOR_DELIVERY");
    }

    @Override public void deliver(Order order) { System.out.println("    Order not out for delivery"); }
    @Override public void cancel(Order order) { System.out.println("    Cannot cancel once the kitchen has started"); }

    @Override public String name() { return "PREPARING"; }
}
