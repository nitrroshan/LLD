package chapter42;

/**
 * Demo — a capacity-bounded cache with pluggable eviction (Strategy), a caching
 * proxy over a slow source (Proxy), and a shared CacheManager (Singleton).
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== LRU Cache Demo (Java) ===\n");

        // 1) LRU eviction order.
        System.out.println("Scenario 1: LRU (capacity 3)");
        Cache<Integer, String> lru = new Cache<>(3, new LruEvictionPolicy<>());
        lru.put(1, "a");
        lru.put(2, "b");
        lru.put(3, "c");
        lru.get(1);            // 1 is now most-recently-used
        lru.put(4, "d");       // full -> evicts LRU = 2
        System.out.println("  get(2) -> " + lru.get(2) + " (evicted)");
        System.out.println("  get(1) -> " + lru.get(1) + " (still present)");

        // 2) Same access pattern, different policy => different victim (Strategy).
        System.out.println("\nScenario 2: FIFO vs LFU on the same pattern");
        System.out.println(" FIFO:");
        runPattern(new FifoEvictionPolicy<>());   // evicts oldest inserted = 1
        System.out.println(" LFU:");
        runPattern(new LfuEvictionPolicy<>());    // evicts least frequently used = 2

        // 3) Caching proxy over a slow source (Proxy).
        System.out.println("\nScenario 3: caching proxy over a slow source");
        DataSource<Integer, String> src = new CacheProxy<>(new RealDataSource(),
                new Cache<>(2, new LruEvictionPolicy<>()));
        System.out.println("  " + src.get(42));   // miss -> DB
        System.out.println("  " + src.get(42));   // hit -> cache

        // 4) Singleton shared cache.
        System.out.println("\nScenario 4: Singleton CacheManager");
        System.out.println("  " + CacheManager.getInstance().getUser(7));   // miss -> DB
        System.out.println("  " + CacheManager.getInstance().getUser(7));   // hit -> cache
        System.out.println("  same instance? "
                + (CacheManager.getInstance() == CacheManager.getInstance()));
    }

    /** Fills a capacity-2 cache with 1 and 2, accesses 1 twice, then inserts 3. */
    private static void runPattern(EvictionPolicy<Integer> policy) {
        Cache<Integer, String> cache = new Cache<>(2, policy);
        cache.put(1, "a");
        cache.put(2, "b");
        cache.get(1);
        cache.get(1);       // 1 accessed more often (matters for LFU only)
        cache.put(3, "c");  // full -> evict per policy
    }
}
