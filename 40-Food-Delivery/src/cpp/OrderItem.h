#pragma once
#include "MenuItem.h"

// A line item in an order: a menu item and how many.
class OrderItem {
    MenuItem item_;
    int quantity_;
public:
    OrderItem(MenuItem item, int quantity) : item_(std::move(item)), quantity_(quantity) {}
    const MenuItem& item() const { return item_; }
    int quantity() const { return quantity_; }
    double subtotal() const { return item_.price() * quantity_; }
};
