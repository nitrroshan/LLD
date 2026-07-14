package chapter39;

/**
 * RealSubject — the "expensive" distance computation (imagine a maps/routing
 * call). Prints when it actually computes so the proxy's caching is visible.
 */
public class RealLocationService implements LocationService {
    @Override
    public double getDistance(Location a, Location b) {
        System.out.println("    [LocationService] computing distance " + a + " -> " + b);
        return a.distanceTo(b);
    }
}
