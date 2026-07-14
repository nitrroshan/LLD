package chapter42;

/**
 * The thing being cached — a source of values by key.
 */
public interface DataSource<K, V> {
    V get(K key);
}
