package chapter39;

import java.util.List;

/**
 * Matching — pick the closest available driver to the pickup. Uses the
 * LocationService (a caching proxy) for distances.
 */
public class NearestDriverMatchingStrategy implements RideMatchingStrategy {
    @Override
    public Driver selectDriver(List<Driver> candidates, Location pickup, LocationService locationService) {
        Driver best = null;
        double bestDistance = Double.MAX_VALUE;
        for (Driver driver : candidates) {
            double distance = locationService.getDistance(pickup, driver.location());
            if (distance < bestDistance) {
                bestDistance = distance;
                best = driver;
            }
        }
        return best;
    }
}
