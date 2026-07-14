package chapter40;

/**
 * Observer — reacts to order status changes without the order knowing the listener.
 */
public interface OrderObserver {
    void onStatusChanged(Order order, String status);
}
