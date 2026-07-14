package chapter42;

/**
 * Strategy — the eviction policy. It owns ONLY the bookkeeping needed to decide
 * which key to evict; the Cache owns the key->value storage. This split is what
 * makes LRU / LFU / FIFO interchangeable.
 */
public interface EvictionPolicy<K> {
    /** A brand-new key was inserted into the cache. */
    void keyAdded(K key);

    /** An existing key was read or updated. */
    void keyAccessed(K key);

    /** Choose and remove (from the policy's bookkeeping) the key to evict. */
    K evictKey();
}
