package chapter42;

import java.util.LinkedHashSet;

/**
 * Least Recently Used — evict the key that was accessed longest ago.
 * A LinkedHashSet keeps keys in access order; re-inserting on access moves a key
 * to the most-recent end, and the eldest (iteration start) is the LRU victim.
 */
public class LruEvictionPolicy<K> implements EvictionPolicy<K> {
    private final LinkedHashSet<K> order = new LinkedHashSet<>();

    @Override
    public void keyAdded(K key) {
        order.add(key);   // newest at the end
    }

    @Override
    public void keyAccessed(K key) {
        order.remove(key);
        order.add(key);   // move to the most-recent end
    }

    @Override
    public K evictKey() {
        K eldest = order.iterator().next();   // least recently used
        order.remove(eldest);
        return eldest;
    }
}
