package chapter29;

import java.util.List;

/**
 * Concrete Strategy — pick the elevator whose current floor is closest to the
 * requested floor.
 */
public class NearestElevatorStrategy implements SchedulingStrategy {
    @Override
    public Elevator select(List<Elevator> elevators, Request request) {
        Elevator best = null;
        int bestDistance = Integer.MAX_VALUE;
        for (Elevator elevator : elevators) {
            int distance = Math.abs(elevator.getCurrentFloor() - request.floor());
            if (distance < bestDistance) {
                bestDistance = distance;
                best = elevator;
            }
        }
        return best;
    }
}
