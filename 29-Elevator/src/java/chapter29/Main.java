package chapter29;

import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Elevator System Demo ===\n");

        // Two elevators; E1 starts at floor 0, E2 at floor 5.
        Elevator e1 = new Elevator("E1", 0);
        Elevator e2 = new Elevator("E2", 5);

        // Each has a floor display observing its movement.
        e1.registerObserver(new FloorDisplay());
        e2.registerObserver(new FloorDisplay());

        List<Elevator> elevators = Arrays.asList(e1, e2);
        ElevatorController controller =
                new ElevatorController(elevators, new NearestElevatorStrategy());

        // Hall calls — the controller picks the nearest elevator.
        System.out.println("Submitting hall calls:");
        controller.submit(new HallRequest(3, Direction.UP));   // nearest to 3: E2 (5) vs E1 (0)
        controller.submit(new HallRequest(1, Direction.UP));   // nearest to 1: E1

        System.out.println("\nRunning simulation:");
        controller.run(12);

        // A passenger who boarded E1 now presses a floor button inside (car request).
        System.out.println("\nCar request inside E1 to floor 6:");
        new CarRequest(6).executeOn(e1);
        controller.run(12);

        System.out.println("\nScheduling is pluggable — the same controller could use");
        System.out.println("LeastBusyStrategy instead, with no change to the elevators.");
    }
}
