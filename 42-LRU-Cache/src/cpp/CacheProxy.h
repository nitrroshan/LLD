#pragma once
#include <iostream>
#include "DataSource.h"
#include "Cache.h"

// Caching Proxy — same DataSource interface as the real source, but serves hits
// from the cache and only fetches from the real source on a miss. The client
// can't tell caching is happening.
template <class K, class V>
class CacheProxy : public DataSource<K, V> {
    DataSource<K, V>& real_;   // non-owning; the real source lives elsewhere
    Cache<K, V>& cache_;

public:
    CacheProxy(DataSource<K, V>& real, Cache<K, V>& cache) : real_(real), cache_(cache) {}

    V get(const K& key) override {
        V value;
        if (cache_.get(key, value)) {
            std::cout << "    [cache] hit " << key << "\n";
            return value;
        }
        value = real_.get(key);   // miss -> fetch from the slow source
        cache_.put(key, value);
        return value;
    }
};
