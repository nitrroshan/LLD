package chapter42;

import java.util.HashMap;
import java.util.Map;

/**
 * Least Frequently Used — evict the key with the fewest accesses. Frequency is
 * tracked per key; ties are broken arbitrarily (the first minimum found).
 */
public class LfuEvictionPolicy<K> implements EvictionPolicy<K> {
    private final Map<K, Integer> frequency = new HashMap<>();

    @Override
    public void keyAdded(K key) {
        frequency.put(key, 1);
    }

    @Override
    public void keyAccessed(K key) {
        frequency.merge(key, 1, Integer::sum);
    }

    @Override
    public K evictKey() {
        K victim = null;
        int min = Integer.MAX_VALUE;
        for (Map.Entry<K, Integer> e : frequency.entrySet()) {
            if (e.getValue() < min) {
                min = e.getValue();
                victim = e.getKey();
            }
        }
        frequency.remove(victim);
        return victim;
    }
}
