#pragma once
#include <iostream>
#include <string>
#include "OrderObserver.h"
#include "Order.h"

// Observer — notifies the customer of status changes.
class CustomerNotifier : public OrderObserver {
public:
    void on_status_changed(Order& order, const std::string& status) override {
        std::cout << "    [Customer " << order.customer()->name() << "] order is now " << status << "\n";
    }
};

// Observer — notifies the restaurant of status changes.
class RestaurantNotifier : public OrderObserver {
public:
    void on_status_changed(Order& order, const std::string& status) override {
        std::cout << "    [Restaurant " << order.restaurant()->name() << "] order is now " << status << "\n";
    }
};

// Observer — notifies the assigned agent of status changes.
class DeliveryAgentNotifier : public OrderObserver {
public:
    void on_status_changed(Order& order, const std::string& status) override {
        std::string agent = order.agent() ? order.agent()->name() : "(unassigned)";
        std::cout << "    [Agent " << agent << "] order is now " << status << "\n";
    }
};
