package chapter42;

/**
 * Singleton — global access to one configured, cache-backed data source
 * (an LRU cache in front of the slow store). Built with the Bill Pugh idiom.
 */
public class CacheManager {
    private final DataSource<Integer, String> source;

    private CacheManager() {
        Cache<Integer, String> cache = new Cache<>(3, new LruEvictionPolicy<>());
        this.source = new CacheProxy<>(new RealDataSource(), cache);
    }

    private static class Holder {
        private static final CacheManager INSTANCE = new CacheManager();
    }

    public static CacheManager getInstance() {
        return Holder.INSTANCE;
    }

    public String getUser(int id) {
        return source.get(id);
    }
}
