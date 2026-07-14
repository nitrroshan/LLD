package chapter40;

/**
 * State — the order lifecycle. Each concrete state defines which actions are
 * legal and what transition follows; illegal actions are refused.
 */
public interface OrderState {
    void confirm(Order order);
    void prepare(Order order);
    void dispatch(Order order, DeliveryAgent agent);
    void deliver(Order order);
    void cancel(Order order);
    String name();
}
