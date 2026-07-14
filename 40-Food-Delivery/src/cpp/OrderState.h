#pragma once

class Order;
class DeliveryAgent;

// State — the order lifecycle. Each concrete state defines which actions are
// legal and what transition follows; illegal actions are refused. Stateless
// singletons that take the Order& as a parameter.
class OrderState {
public:
    virtual ~OrderState() = default;
    virtual void confirm(Order& order) = 0;
    virtual void prepare(Order& order) = 0;
    virtual void dispatch(Order& order, DeliveryAgent* agent) = 0;
    virtual void deliver(Order& order) = 0;
    virtual void cancel(Order& order) = 0;
    virtual const char* name() const = 0;
};
