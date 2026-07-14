#include <iostream>
#include <vector>
#include "FoodDeliveryService.h"
#include "Restaurant.h"
#include "Menu.h"
#include "MenuItem.h"
#include "Customer.h"
#include "DeliveryAgent.h"
#include "OrderItem.h"
#include "Location.h"

int main() {
    std::cout << "=== Food Delivery Demo (C++) ===\n\n";

    FoodDeliveryService service;

    // A restaurant with a menu.
    Menu menu;
    MenuItem biryani("Biryani", 250);
    MenuItem naan("Naan", 40);
    MenuItem lassi("Lassi", 60);
    menu.add_item(biryani);
    menu.add_item(naan);
    menu.add_item(lassi);
    Restaurant restaurant("RE1", "Spice Hub", Location(5, 5), menu);
    service.register_restaurant(&restaurant);

    // Delivery agents.
    DeliveryAgent sam("A1", "Sam", Location(4, 6));
    DeliveryAgent nina("A2", "Nina", Location(9, 9));
    service.register_agent(&sam);
    service.register_agent(&nina);

    Customer customer("C1", "Dave", Location(0, 0));
    NearestAgentAssignmentStrategy nearest;

    // 1) Full lifecycle, COD, distance-based fee.
    std::cout << "Scenario 1: place -> confirm -> prepare -> dispatch -> deliver (COD)\n";
    DistanceBasedPricingStrategy distance_pricing(20, 5);
    std::vector<OrderItem> cart{ OrderItem(biryani, 1), OrderItem(naan, 2) };
    Order* order = service.place_order(customer, restaurant, cart, distance_pricing, PaymentType::Cod);
    service.confirm_order(order);
    service.prepare_order(order);
    service.dispatch_order(order, nearest);   // nearest agent is Sam (4,6)
    service.deliver_order(order);

    // 2) Free delivery above a threshold (big order), paid by UPI.
    std::cout << "\nScenario 2: free delivery above threshold (UPI)\n";
    FreeAboveThresholdPricingStrategy free_pricing(400, 30);
    std::vector<OrderItem> big_cart{ OrderItem(biryani, 2), OrderItem(lassi, 2) };
    service.place_order(customer, restaurant, big_cart, free_pricing, PaymentType::Upi);

    // 3) Cancel before the kitchen starts.
    std::cout << "\nScenario 3: cancel before preparing\n";
    std::vector<OrderItem> small_cart{ OrderItem(lassi, 1) };
    Order* to_cancel = service.place_order(customer, restaurant, small_cart, distance_pricing, PaymentType::Wallet);
    service.confirm_order(to_cancel);
    to_cancel->cancel();
    std::cout << "  Order state: " << to_cancel->state_name() << "\n";

    // 4) Illegal action: cannot deliver a delivered order.
    std::cout << "\nScenario 4: illegal action on a delivered order\n";
    order->deliver();

    return 0;
}
