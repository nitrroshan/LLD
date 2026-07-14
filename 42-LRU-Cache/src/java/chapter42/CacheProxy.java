package chapter42;

/**
 * Caching Proxy — same DataSource interface as the real source, but serves hits
 * from the cache and only fetches from the real source on a miss. The client
 * can't tell caching is happening.
 */
public class CacheProxy<K, V> implements DataSource<K, V> {
    private final DataSource<K, V> real;
    private final Cache<K, V> cache;

    public CacheProxy(DataSource<K, V> real, Cache<K, V> cache) {
        this.real = real;
        this.cache = cache;
    }

    @Override
    public V get(K key) {
        V cached = cache.get(key);
        if (cached != null) {
            System.out.println("    [cache] hit " + key);
            return cached;
        }
        V value = real.get(key);   // miss -> fetch from the slow source
        cache.put(key, value);
        return value;
    }
}
