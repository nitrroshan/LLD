package chapter28;

import java.util.ArrayList;
import java.util.List;

/**
 * A floor holding many spots. Owns the search for an available spot so the
 * lot doesn't need to know spot internals.
 */
public class ParkingFloor {
    private final int floorNumber;
    private final List<ParkingSpot> spots = new ArrayList<>();

    public ParkingFloor(int floorNumber) {
        this.floorNumber = floorNumber;
    }

    public int getFloorNumber() {
        return floorNumber;
    }

    public void addSpot(ParkingSpot spot) {
        spots.add(spot);
    }

    /** First-fit: return the first free spot that can hold the vehicle. */
    public ParkingSpot findAvailableSpot(Vehicle vehicle) {
        for (ParkingSpot spot : spots) {
            if (spot.canFit(vehicle)) {
                return spot;
            }
        }
        return null;
    }

    public int availableCount() {
        int count = 0;
        for (ParkingSpot spot : spots) {
            if (spot.isAvailable()) {
                count++;
            }
        }
        return count;
    }

    public int totalSpots() {
        return spots.size();
    }
}
