#pragma once
#include <string>
#include <unordered_map>

// Context — holds the boolean value bound to each variable name.
class Context {
    std::unordered_map<std::string, bool> values_;

public:
    void set(const std::string& name, bool value) {
        values_[name] = value;
    }

    bool get(const std::string& name) const {
        auto it = values_.find(name);
        return it != values_.end() && it->second;
    }
};
