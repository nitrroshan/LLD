#include <iostream>
#include <memory>
#include <string>
#include "Cache.h"
#include "LruEvictionPolicy.h"
#include "FifoEvictionPolicy.h"
#include "LfuEvictionPolicy.h"
#include "CacheProxy.h"
#include "RealDataSource.h"
#include "CacheManager.h"

// Fills a capacity-2 cache with 1 and 2, accesses 1 twice, then inserts 3.
static void run_pattern(std::unique_ptr<EvictionPolicy<int>> policy) {
    Cache<int, std::string> cache(2, std::move(policy));
    cache.put(1, "a");
    cache.put(2, "b");
    std::string tmp;
    cache.get(1, tmp);
    cache.get(1, tmp);   // 1 accessed more often (matters for LFU only)
    cache.put(3, "c");   // full -> evict per policy
}

int main() {
    std::cout << "=== LRU Cache Demo (C++) ===\n\n";

    // 1) LRU eviction order.
    std::cout << "Scenario 1: LRU (capacity 3)\n";
    Cache<int, std::string> lru(3, std::make_unique<LruEvictionPolicy<int>>());
    lru.put(1, "a");
    lru.put(2, "b");
    lru.put(3, "c");
    std::string v;
    lru.get(1, v);          // 1 is now most-recently-used
    lru.put(4, "d");        // full -> evicts LRU = 2
    std::cout << "  get(2) -> " << (lru.get(2, v) ? v : "MISS") << " (evicted)\n";
    std::cout << "  get(1) -> " << (lru.get(1, v) ? v : "MISS") << " (still present)\n";

    // 2) Same access pattern, different policy => different victim (Strategy).
    std::cout << "\nScenario 2: FIFO vs LFU on the same pattern\n";
    std::cout << " FIFO:\n";
    run_pattern(std::make_unique<FifoEvictionPolicy<int>>());   // evicts oldest inserted = 1
    std::cout << " LFU:\n";
    run_pattern(std::make_unique<LfuEvictionPolicy<int>>());    // evicts least frequently used = 2

    // 3) Caching proxy over a slow source (Proxy).
    std::cout << "\nScenario 3: caching proxy over a slow source\n";
    RealDataSource real;
    Cache<int, std::string> proxy_cache(2, std::make_unique<LruEvictionPolicy<int>>());
    CacheProxy<int, std::string> src(real, proxy_cache);
    std::cout << "  " << src.get(42) << "\n";   // miss -> DB
    std::cout << "  " << src.get(42) << "\n";   // hit -> cache

    // 4) Singleton shared cache.
    std::cout << "\nScenario 4: Singleton CacheManager\n";
    std::cout << "  " << CacheManager::instance().get_user(7) << "\n";   // miss -> DB
    std::cout << "  " << CacheManager::instance().get_user(7) << "\n";   // hit -> cache
    std::cout << "  same instance? "
              << (&CacheManager::instance() == &CacheManager::instance() ? "true" : "false") << "\n";

    return 0;
}
