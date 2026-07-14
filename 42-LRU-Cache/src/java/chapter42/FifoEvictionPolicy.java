package chapter42;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * First In, First Out — evict in insertion order; access does not matter.
 */
public class FifoEvictionPolicy<K> implements EvictionPolicy<K> {
    private final Deque<K> queue = new ArrayDeque<>();

    @Override
    public void keyAdded(K key) {
        queue.addLast(key);
    }

    @Override
    public void keyAccessed(K key) {
        // FIFO ignores access.
    }

    @Override
    public K evictKey() {
        return queue.removeFirst();   // oldest inserted
    }
}
