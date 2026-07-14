package chapter29;

import java.util.List;

/**
 * Concrete Strategy — pick the elevator with the fewest pending stops.
 */
public class LeastBusyStrategy implements SchedulingStrategy {
    @Override
    public Elevator select(List<Elevator> elevators, Request request) {
        Elevator best = null;
        int fewest = Integer.MAX_VALUE;
        for (Elevator elevator : elevators) {
            if (elevator.targetCount() < fewest) {
                fewest = elevator.targetCount();
                best = elevator;
            }
        }
        return best;
    }
}
