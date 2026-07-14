package chapter40;

import java.util.ArrayList;
import java.util.List;

/**
 * Context — an order. Holds the customer, restaurant, items, assigned agent,
 * total, current State, and observers. Lifecycle actions delegate to the state.
 */
public class Order {
    private final String id;
    private final Customer customer;
    private final Restaurant restaurant;
    private final List<OrderItem> items;
    private DeliveryAgent agent;
    private final double total;
    private OrderState state = PlacedState.instance();
    private final List<OrderObserver> observers = new ArrayList<>();

    public Order(String id, Customer customer, Restaurant restaurant, List<OrderItem> items, double total) {
        this.id = id;
        this.customer = customer;
        this.restaurant = restaurant;
        this.items = items;
        this.total = total;
    }

    public void addObserver(OrderObserver observer) { observers.add(observer); }
    public void notifyObservers(String status) {
        for (OrderObserver o : observers) o.onStatusChanged(this, status);
    }

    // Lifecycle actions — delegate to the current state.
    public void confirm() { state.confirm(this); }
    public void prepare() { state.prepare(this); }
    public void dispatch(DeliveryAgent agent) { state.dispatch(this, agent); }
    public void deliver() { state.deliver(this); }
    public void cancel() { state.cancel(this); }

    public void setState(OrderState state) { this.state = state; }
    public String stateName() { return state.name(); }
    public String id() { return id; }
    public Customer customer() { return customer; }
    public Restaurant restaurant() { return restaurant; }
    public List<OrderItem> items() { return items; }
    public DeliveryAgent agent() { return agent; }
    public void setAgent(DeliveryAgent agent) { this.agent = agent; }
    public double total() { return total; }
}
