#pragma once
#include <vector>
#include "MenuItem.h"

// A restaurant's menu — a list of items.
class Menu {
    std::vector<MenuItem> items_;
public:
    void add_item(const MenuItem& item) { items_.push_back(item); }
    const std::vector<MenuItem>& items() const { return items_; }
};
