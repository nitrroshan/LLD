#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "LocationService.h"

// Caching Proxy — memoizes distance lookups behind the LocationService
// interface, so repeated queries don't recompute. Safe for fixed demo
// distances; live driver positions would need a short TTL (see notes).
class CachingLocationServiceProxy : public LocationService {
    LocationService& real_;                        // wraps the real service (non-owning)
    std::unordered_map<std::string, double> cache_;
public:
    explicit CachingLocationServiceProxy(LocationService& real) : real_(real) {}

    double get_distance(const Location& a, const Location& b) override {
        std::string key = a.to_string() + "|" + b.to_string();
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            std::cout << "    [LocationService] cache hit " << a.to_string()
                      << " -> " << b.to_string() << "\n";
            return it->second;
        }
        double distance = real_.get_distance(a, b);
        cache_[key] = distance;
        return distance;
    }
};
