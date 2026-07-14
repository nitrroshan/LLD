#pragma once
#include <string>
#include <memory>
#include "DataSource.h"
#include "Cache.h"
#include "CacheProxy.h"
#include "RealDataSource.h"
#include "LruEvictionPolicy.h"

// Singleton — global access to one configured, cache-backed data source (an LRU
// cache in front of the slow store). Meyer's Singleton: lazy + thread-safe init.
class CacheManager {
    RealDataSource real_;
    Cache<int, std::string> cache_;
    CacheProxy<int, std::string> proxy_;   // declared after real_/cache_ (init order)

    CacheManager()
        : cache_(3, std::make_unique<LruEvictionPolicy<int>>()),
          proxy_(real_, cache_) {}

public:
    CacheManager(const CacheManager&) = delete;
    CacheManager& operator=(const CacheManager&) = delete;

    static CacheManager& instance() {
        static CacheManager manager;
        return manager;
    }

    std::string get_user(int id) { return proxy_.get(id); }
};
