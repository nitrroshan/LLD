package chapter42;

import java.util.HashMap;
import java.util.Map;

/**
 * A fixed-capacity cache. Owns the key->value store and delegates the
 * "who to evict" decision to a pluggable EvictionPolicy (Strategy).
 */
public class Cache<K, V> {
    private final int capacity;
    private final Map<K, V> store = new HashMap<>();
    private final EvictionPolicy<K> policy;

    public Cache(int capacity, EvictionPolicy<K> policy) {
        this.capacity = capacity;
        this.policy = policy;
    }

    /** Returns the value or null on a miss. A hit updates the policy. */
    public V get(K key) {
        if (!store.containsKey(key)) {
            return null;
        }
        policy.keyAccessed(key);
        return store.get(key);
    }

    public void put(K key, V value) {
        if (store.containsKey(key)) {
            store.put(key, value);
            policy.keyAccessed(key);
            return;
        }
        if (store.size() >= capacity) {
            K victim = policy.evictKey();     // Strategy decides the victim
            store.remove(victim);
            System.out.println("    evicted " + victim);
        }
        store.put(key, value);
        policy.keyAdded(key);
    }

    public boolean contains(K key) { return store.containsKey(key); }
    public int size() { return store.size(); }
}
