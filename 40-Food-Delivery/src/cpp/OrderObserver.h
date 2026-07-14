#pragma once
#include <string>

class Order;

// Observer — reacts to order status changes without the order knowing the listener.
class OrderObserver {
public:
    virtual ~OrderObserver() = default;
    virtual void on_status_changed(Order& order, const std::string& status) = 0;
};
