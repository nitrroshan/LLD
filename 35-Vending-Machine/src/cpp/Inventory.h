#pragma once
#include <string>
#include <unordered_map>
#include "Product.h"

// Products keyed by slot code, with per-slot stock counts.
class Inventory {
    std::unordered_map<std::string, Product> products_;
    std::unordered_map<std::string, int> stock_;

public:
    void add_product(const Product& product, int quantity) {
        products_.emplace(product.code(), product);
        stock_[product.code()] = quantity;
    }

    Product* get_product(const std::string& code) {
        auto it = products_.find(code);
        return it != products_.end() ? &it->second : nullptr;
    }

    bool is_in_stock(const std::string& code) const {
        auto it = stock_.find(code);
        return it != stock_.end() && it->second > 0;
    }

    void reduce_stock(const std::string& code) {
        stock_[code]--;
    }

    int stock(const std::string& code) const {
        auto it = stock_.find(code);
        return it != stock_.end() ? it->second : 0;
    }
};
