#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <iostream>
#include "TreeType.h"

// Flyweight Factory — creates and caches shared TreeType flyweights.
// The same intrinsic combination always returns the SAME shared_ptr.
class TreeFactory {
    std::unordered_map<std::string, std::shared_ptr<const TreeType>> cache_;

public:
    std::shared_ptr<const TreeType> get_tree_type(const std::string& name,
                                                  const std::string& color,
                                                  const std::string& texture) {
        std::string key = name + "-" + color + "-" + texture;
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            return it->second;
        }
        std::cout << "  [Factory] Creating new TreeType: " << key << "\n";
        auto type = std::make_shared<const TreeType>(name, color, texture);
        cache_[key] = type;
        return type;
    }

    std::size_t distinct_type_count() const { return cache_.size(); }
};
