package chapter39;

import java.util.HashMap;
import java.util.Map;

/**
 * Caching Proxy — memoizes distance lookups behind the LocationService
 * interface, so repeated queries (same pickup vs many drivers, or a repeated
 * pickup->drop quote) don't recompute. Safe here because the demo distances are
 * fixed; live driver positions would need a short TTL instead (see notes).
 */
public class CachingLocationServiceProxy implements LocationService {
    private final LocationService real;
    private final Map<String, Double> cache = new HashMap<>();

    public CachingLocationServiceProxy(LocationService real) {
        this.real = real;
    }

    @Override
    public double getDistance(Location a, Location b) {
        String key = a + "|" + b;
        Double cached = cache.get(key);
        if (cached != null) {
            System.out.println("    [LocationService] cache hit " + a + " -> " + b);
            return cached;
        }
        double distance = real.getDistance(a, b);
        cache.put(key, distance);
        return distance;
    }
}
