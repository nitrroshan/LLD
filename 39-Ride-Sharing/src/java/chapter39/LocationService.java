package chapter39;

/**
 * Proxy subject — computes the distance between two locations. Real and proxy
 * implementations share this interface, so callers can't tell them apart.
 */
public interface LocationService {
    double getDistance(Location a, Location b);
}
