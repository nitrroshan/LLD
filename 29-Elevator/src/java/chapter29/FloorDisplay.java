package chapter29;

/**
 * Concrete Observer — a display that shows an elevator's live position.
 */
public class FloorDisplay implements ElevatorObserver {
    @Override
    public void update(Elevator elevator) {
        System.out.printf("    [Display %s] floor %d, %s %s%n",
                elevator.getId(),
                elevator.getCurrentFloor(),
                elevator.getStatus(),
                elevator.getDirection());
    }
}
