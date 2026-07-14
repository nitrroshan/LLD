package chapter40;

import java.util.ArrayList;
import java.util.List;

/**
 * Coordinator — registers restaurants and agents and orchestrates an order:
 * price delivery (Strategy), pay via a factory-built method (Factory), create
 * the Order (State), assign the nearest agent on dispatch (Strategy), and notify
 * customer / restaurant / agent (Observer).
 */
public class FoodDeliveryService {
    private final List<Restaurant> restaurants = new ArrayList<>();
    private final List<DeliveryAgent> agents = new ArrayList<>();
    private int counter = 0;

    public void registerRestaurant(Restaurant restaurant) { restaurants.add(restaurant); }
    public void registerAgent(DeliveryAgent agent) { agents.add(agent); }

    public Order placeOrder(Customer customer, Restaurant restaurant, List<OrderItem> items,
                            DeliveryPricingStrategy pricing, PaymentType paymentType) {
        double subtotal = 0;
        for (OrderItem item : items) subtotal += item.subtotal();
        double distance = customer.location().distanceTo(restaurant.location());
        double fee = pricing.calculateFee(distance, subtotal);          // Strategy
        double total = subtotal + fee;

        PaymentMethod payment = PaymentFactory.create(paymentType);      // Factory
        if (!payment.pay(total)) {
            System.out.println("  Payment failed — order not placed");
            return null;
        }

        Order order = new Order("O" + (++counter), customer, restaurant, items, total);
        order.addObserver(new CustomerNotifier());
        order.addObserver(new RestaurantNotifier());
        System.out.printf("  Order %s placed: subtotal %.1f + delivery %.1f = %.1f%n",
                order.id(), subtotal, fee, total);
        order.notifyObservers("PLACED");
        return order;
    }

    public void confirmOrder(Order order) { order.confirm(); }
    public void prepareOrder(Order order) { order.prepare(); }

    public void dispatchOrder(Order order, DeliveryAssignmentStrategy assignment) {
        List<DeliveryAgent> free = new ArrayList<>();
        for (DeliveryAgent a : agents) if (a.isAvailable()) free.add(a);
        if (free.isEmpty()) {
            System.out.println("  No available delivery agents");
            return;
        }
        DeliveryAgent agent = assignment.selectAgent(free, order.restaurant().location());  // Strategy
        order.addObserver(new DeliveryAgentNotifier());   // agent now tracks the order
        order.dispatch(agent);                             // State: Preparing -> OutForDelivery
        agent.setAvailable(false);
    }

    public void deliverOrder(Order order) {
        order.deliver();
        if (order.agent() != null) order.agent().setAvailable(true);
    }
}
