#pragma once
#include <vector>
#include <memory>
#include <string>
#include "OrderState.h"
#include "OrderObserver.h"
#include "Customer.h"
#include "Restaurant.h"
#include "OrderItem.h"
#include "DeliveryAgent.h"

// Context — an order. Holds the customer, restaurant, items, assigned agent,
// total, current State, and observers. Lifecycle actions delegate to the state.
// The initial state is set by the service (which knows the concrete states).
class Order {
    std::string id_;
    Customer* customer_;
    Restaurant* restaurant_;
    std::vector<OrderItem> items_;
    DeliveryAgent* agent_ = nullptr;
    double total_;
    OrderState* state_ = nullptr;
    std::vector<std::unique_ptr<OrderObserver>> observers_;

public:
    Order(std::string id, Customer* customer, Restaurant* restaurant,
          std::vector<OrderItem> items, double total)
        : id_(std::move(id)), customer_(customer), restaurant_(restaurant),
          items_(std::move(items)), total_(total) {}

    void add_observer(std::unique_ptr<OrderObserver> o) { observers_.push_back(std::move(o)); }
    void notify_observers(const std::string& status) {
        for (auto& o : observers_) o->on_status_changed(*this, status);
    }

    // Lifecycle actions — delegate to the current state.
    void confirm() { state_->confirm(*this); }
    void prepare() { state_->prepare(*this); }
    void dispatch(DeliveryAgent* agent) { state_->dispatch(*this, agent); }
    void deliver() { state_->deliver(*this); }
    void cancel() { state_->cancel(*this); }

    void set_state(OrderState* s) { state_ = s; }
    const char* state_name() const { return state_->name(); }
    const std::string& id() const { return id_; }
    Customer* customer() const { return customer_; }
    Restaurant* restaurant() const { return restaurant_; }
    DeliveryAgent* agent() const { return agent_; }
    void set_agent(DeliveryAgent* a) { agent_ = a; }
    double total() const { return total_; }
};
