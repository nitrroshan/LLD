#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <iomanip>
#include "Restaurant.h"
#include "DeliveryAgent.h"
#include "Customer.h"
#include "OrderItem.h"
#include "Order.h"
#include "OrderStates.h"
#include "OrderObservers.h"
#include "Payment.h"
#include "PaymentType.h"
#include "DeliveryAssignmentStrategy.h"
#include "PricingStrategies.h"

// Coordinator — registers restaurants and agents and orchestrates an order:
// price delivery (Strategy), pay via a factory-built method (Factory), create
// the Order (State), assign the nearest agent on dispatch (Strategy), and notify
// customer / restaurant / agent (Observer).
class FoodDeliveryService {
    std::vector<Restaurant*> restaurants_;
    std::vector<DeliveryAgent*> agents_;
    std::vector<std::unique_ptr<Order>> orders_;
    int counter_ = 0;

public:
    void register_restaurant(Restaurant* restaurant) { restaurants_.push_back(restaurant); }
    void register_agent(DeliveryAgent* agent) { agents_.push_back(agent); }

    Order* place_order(Customer& customer, Restaurant& restaurant, std::vector<OrderItem> items,
                       const DeliveryPricingStrategy& pricing, PaymentType payment_type) {
        double subtotal = 0;
        for (const auto& item : items) subtotal += item.subtotal();
        double distance = customer.location().distance_to(restaurant.location());
        double fee = pricing.calculate_fee(distance, subtotal);          // Strategy
        double total = subtotal + fee;

        auto payment = PaymentFactory::create(payment_type);             // Factory
        if (!payment->pay(total)) {
            std::cout << "  Payment failed - order not placed\n";
            return nullptr;
        }

        auto order = std::make_unique<Order>("O" + std::to_string(++counter_),
                                             &customer, &restaurant, std::move(items), total);
        order->set_state(&PlacedState::instance());
        order->add_observer(std::make_unique<CustomerNotifier>());
        order->add_observer(std::make_unique<RestaurantNotifier>());
        Order* raw = order.get();
        orders_.push_back(std::move(order));

        std::cout << "  Order " << raw->id() << " placed: subtotal " << std::fixed << std::setprecision(1)
                  << subtotal << " + delivery " << fee << " = " << total << "\n";
        raw->notify_observers("PLACED");
        return raw;
    }

    void confirm_order(Order* order) { order->confirm(); }
    void prepare_order(Order* order) { order->prepare(); }

    void dispatch_order(Order* order, const DeliveryAssignmentStrategy& assignment) {
        std::vector<DeliveryAgent*> free;
        for (auto* a : agents_) if (a->is_available()) free.push_back(a);
        if (free.empty()) {
            std::cout << "  No available delivery agents\n";
            return;
        }
        DeliveryAgent* agent = assignment.select_agent(free, order->restaurant()->location());  // Strategy
        order->add_observer(std::make_unique<DeliveryAgentNotifier>());   // agent now tracks
        order->dispatch(agent);                                          // State: Preparing -> OutForDelivery
        agent->set_available(false);
    }

    void deliver_order(Order* order) {
        order->deliver();
        if (order->agent()) order->agent()->set_available(true);
    }
};
