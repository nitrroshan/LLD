#pragma once
#include "Shape.h"
#include <unordered_map>
#include <stdexcept>

class ShapeRegistry {
private:
    std::unordered_map<std::string, std::unique_ptr<Shape>> prototypes_;

public:
    void register_shape(const std::string& key, std::unique_ptr<Shape> shape) {
        prototypes_[key] = std::move(shape);
    }

    std::unique_ptr<Shape> get(const std::string& key) const {
        auto it = prototypes_.find(key);
        if (it == prototypes_.end()) {
            throw std::invalid_argument("Unknown prototype: " + key);
        }
        return it->second->clone();  // return a CLONE, not the original
    }

    bool contains(const std::string& key) const {
        return prototypes_.find(key) != prototypes_.end();
    }

    size_t size() const { return prototypes_.size(); }
};
