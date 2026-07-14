#pragma once
#include <string>

// A vendable item with a price in cents.
class Product {
    std::string code_;
    std::string name_;
    int price_cents_;

public:
    Product(std::string code, std::string name, int price_cents)
        : code_(std::move(code)), name_(std::move(name)), price_cents_(price_cents) {}

    const std::string& code() const { return code_; }
    const std::string& name() const { return name_; }
    int price_cents() const { return price_cents_; }
};
