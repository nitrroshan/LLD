#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

// ConfigManager Singleton — Meyer's Singleton approach (C++11 thread-safe).
class ConfigManager {
private:
    std::unordered_map<std::string, std::string> properties_;

    ConfigManager() {
        load_defaults();
    }

    void load_defaults() {
        properties_["app.name"] = "LLD Learning App";
        properties_["app.version"] = "1.0";
        properties_["db.host"] = "localhost";
        properties_["db.port"] = "5432";
        properties_["log.level"] = "INFO";
    }

public:
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    static ConfigManager& get_instance() {
        static ConfigManager instance;
        return instance;
    }

    std::string get(const std::string& key) const {
        auto it = properties_.find(key);
        return (it != properties_.end()) ? it->second : "";
    }

    void set(const std::string& key, const std::string& value) {
        properties_[key] = value;
    }

    size_t size() const {
        return properties_.size();
    }
};
