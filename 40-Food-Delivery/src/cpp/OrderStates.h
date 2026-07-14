#pragma once
#include <iostream>
#include "OrderState.h"
#include "Order.h"
#include "DeliveryAgent.h"

// Concrete states as stateless singletons. Declarations first, then out-of-line
// inline definitions so a state can reference its siblings' singletons.

class PlacedState : public OrderState {
public:
    static PlacedState& instance() { static PlacedState s; return s; }
    void confirm(Order& order) override;
    void prepare(Order&) override { std::cout << "    Order not confirmed yet\n"; }
    void dispatch(Order&, DeliveryAgent*) override { std::cout << "    Order not ready\n"; }
    void deliver(Order&) override { std::cout << "    Order not out for delivery\n"; }
    void cancel(Order& order) override;
    const char* name() const override { return "PLACED"; }
};

class ConfirmedState : public OrderState {
public:
    static ConfirmedState& instance() { static ConfirmedState s; return s; }
    void confirm(Order&) override { std::cout << "    Order already confirmed\n"; }
    void prepare(Order& order) override;
    void dispatch(Order&, DeliveryAgent*) override { std::cout << "    Order not ready\n"; }
    void deliver(Order&) override { std::cout << "    Order not out for delivery\n"; }
    void cancel(Order& order) override;
    const char* name() const override { return "CONFIRMED"; }
};

class PreparingState : public OrderState {
public:
    static PreparingState& instance() { static PreparingState s; return s; }
    void confirm(Order&) override { std::cout << "    Order already preparing\n"; }
    void prepare(Order&) override { std::cout << "    Order already preparing\n"; }
    void dispatch(Order& order, DeliveryAgent* agent) override;
    void deliver(Order&) override { std::cout << "    Order not out for delivery\n"; }
    void cancel(Order&) override { std::cout << "    Cannot cancel once the kitchen has started\n"; }
    const char* name() const override { return "PREPARING"; }
};

class OutForDeliveryState : public OrderState {
public:
    static OutForDeliveryState& instance() { static OutForDeliveryState s; return s; }
    void confirm(Order&) override { std::cout << "    Order already out for delivery\n"; }
    void prepare(Order&) override { std::cout << "    Order already out for delivery\n"; }
    void dispatch(Order&, DeliveryAgent*) override { std::cout << "    Order already dispatched\n"; }
    void deliver(Order& order) override;
    void cancel(Order&) override { std::cout << "    Cannot cancel a delivery in progress\n"; }
    const char* name() const override { return "OUT_FOR_DELIVERY"; }
};

class DeliveredState : public OrderState {
public:
    static DeliveredState& instance() { static DeliveredState s; return s; }
    void confirm(Order&) override { rejected(); }
    void prepare(Order&) override { rejected(); }
    void dispatch(Order&, DeliveryAgent*) override { rejected(); }
    void deliver(Order&) override { rejected(); }
    void cancel(Order&) override { rejected(); }
    const char* name() const override { return "DELIVERED"; }
private:
    static void rejected() { std::cout << "    Order is already delivered\n"; }
};

class CancelledState : public OrderState {
public:
    static CancelledState& instance() { static CancelledState s; return s; }
    void confirm(Order&) override { rejected(); }
    void prepare(Order&) override { rejected(); }
    void dispatch(Order&, DeliveryAgent*) override { rejected(); }
    void deliver(Order&) override { rejected(); }
    void cancel(Order&) override { rejected(); }
    const char* name() const override { return "CANCELLED"; }
private:
    static void rejected() { std::cout << "    Order is already cancelled\n"; }
};

// --- Placed transitions ---
inline void PlacedState::confirm(Order& order) {
    order.set_state(&ConfirmedState::instance());
    order.notify_observers("CONFIRMED");
}
inline void PlacedState::cancel(Order& order) {
    order.set_state(&CancelledState::instance());
    order.notify_observers("CANCELLED");
}

// --- Confirmed transitions ---
inline void ConfirmedState::prepare(Order& order) {
    order.set_state(&PreparingState::instance());
    order.notify_observers("PREPARING");
}
inline void ConfirmedState::cancel(Order& order) {
    order.set_state(&CancelledState::instance());
    order.notify_observers("CANCELLED");
}

// --- Preparing transitions ---
inline void PreparingState::dispatch(Order& order, DeliveryAgent* agent) {
    order.set_agent(agent);
    order.set_state(&OutForDeliveryState::instance());
    order.notify_observers("OUT_FOR_DELIVERY");
}

// --- OutForDelivery transitions ---
inline void OutForDeliveryState::deliver(Order& order) {
    order.set_state(&DeliveredState::instance());
    order.notify_observers("DELIVERED");
}
