package chapter40;

import java.util.List;

/**
 * Demo — places orders that run through the state machine, paying via
 * factory-built methods, assigning the nearest agent at dispatch, pricing
 * delivery with swappable strategies, and notifying all parties.
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== Food Delivery Demo (Java) ===\n");

        FoodDeliveryService service = new FoodDeliveryService();

        // A restaurant with a menu.
        Menu menu = new Menu();
        MenuItem biryani = new MenuItem("Biryani", 250);
        MenuItem naan = new MenuItem("Naan", 40);
        MenuItem lassi = new MenuItem("Lassi", 60);
        menu.addItem(biryani);
        menu.addItem(naan);
        menu.addItem(lassi);
        Restaurant restaurant = new Restaurant("RE1", "Spice Hub", new Location(5, 5), menu);
        service.registerRestaurant(restaurant);

        // Delivery agents.
        service.registerAgent(new DeliveryAgent("A1", "Sam", new Location(4, 6)));
        service.registerAgent(new DeliveryAgent("A2", "Nina", new Location(9, 9)));

        Customer customer = new Customer("C1", "Dave", new Location(0, 0));
        DeliveryAssignmentStrategy nearest = new NearestAgentAssignmentStrategy();

        // 1) Full lifecycle, COD, distance-based fee.
        System.out.println("Scenario 1: place -> confirm -> prepare -> dispatch -> deliver (COD)");
        List<OrderItem> cart = List.of(new OrderItem(biryani, 1), new OrderItem(naan, 2));
        Order order = service.placeOrder(customer, restaurant, cart,
                new DistanceBasedPricingStrategy(20, 5), PaymentType.COD);
        service.confirmOrder(order);
        service.prepareOrder(order);
        service.dispatchOrder(order, nearest);   // nearest agent is Sam (4,6)
        service.deliverOrder(order);

        // 2) Free delivery above a threshold (big order), paid by UPI.
        System.out.println("\nScenario 2: free delivery above threshold (UPI)");
        List<OrderItem> bigCart = List.of(new OrderItem(biryani, 2), new OrderItem(lassi, 2));
        Order big = service.placeOrder(customer, restaurant, bigCart,
                new FreeAboveThresholdPricingStrategy(400, 30), PaymentType.UPI);

        // 3) Cancel before the kitchen starts.
        System.out.println("\nScenario 3: cancel before preparing");
        Order toCancel = service.placeOrder(customer, restaurant, List.of(new OrderItem(lassi, 1)),
                new DistanceBasedPricingStrategy(20, 5), PaymentType.WALLET);
        service.confirmOrder(toCancel);
        toCancel.cancel();
        System.out.println("  Order state: " + toCancel.stateName());

        // 4) Illegal action: cannot deliver a delivered order.
        System.out.println("\nScenario 4: illegal action on a delivered order");
        order.deliver();
    }
}
