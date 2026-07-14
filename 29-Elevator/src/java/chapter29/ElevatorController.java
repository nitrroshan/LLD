package chapter29;

import java.util.List;

/**
 * Coordinates elevators. Assigns hall calls to an elevator via the scheduling
 * strategy, and drives the simulation one tick at a time.
 */
public class ElevatorController {
    private final List<Elevator> elevators;
    private SchedulingStrategy strategy;

    public ElevatorController(List<Elevator> elevators, SchedulingStrategy strategy) {
        this.elevators = elevators;
        this.strategy = strategy;
    }

    public void setStrategy(SchedulingStrategy strategy) {
        this.strategy = strategy;
    }

    public void submit(Request request) {
        Elevator elevator = strategy.select(elevators, request);
        System.out.printf("  Dispatch: %s -> elevator %s%n", request.describe(), elevator.getId());
        request.executeOn(elevator);
    }

    public void step() {
        for (Elevator elevator : elevators) {
            elevator.step();
        }
    }

    public boolean allIdle() {
        for (Elevator elevator : elevators) {
            if (!elevator.isIdle()) {
                return false;
            }
        }
        return true;
    }

    /** Run ticks until every elevator is idle or the cap is reached. */
    public void run(int maxTicks) {
        for (int tick = 1; tick <= maxTicks && !allIdle(); tick++) {
            System.out.println("-- tick " + tick + " --");
            step();
        }
    }
}
