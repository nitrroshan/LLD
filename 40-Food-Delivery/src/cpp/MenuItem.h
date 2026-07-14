#pragma once
#include <string>

// A single priced item on a restaurant's menu.
class MenuItem {
    std::string name_;
    double price_;
public:
    MenuItem(std::string name, double price) : name_(std::move(name)), price_(price) {}
    const std::string& name() const { return name_; }
    double price() const { return price_; }
};
