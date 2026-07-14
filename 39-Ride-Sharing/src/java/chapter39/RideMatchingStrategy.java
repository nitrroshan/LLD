package chapter39;

import java.util.List;

/**
 * Strategy — chooses a driver from the available candidates for a pickup.
 */
public interface RideMatchingStrategy {
    Driver selectDriver(List<Driver> candidates, Location pickup, LocationService locationService);
}
