package chapter29;

/**
 * Concrete Command — an internal car request: a passenger inside a car pressed
 * a floor button. It applies directly to that car (no scheduling needed).
 */
public class CarRequest implements Request {
    private final int targetFloor;

    public CarRequest(int targetFloor) {
        this.targetFloor = targetFloor;
    }

    @Override
    public int floor() {
        return targetFloor;
    }

    @Override
    public Direction direction() {
        return Direction.IDLE;   // a car request has no inherent hall direction
    }

    @Override
    public void executeOn(Elevator elevator) {
        elevator.addTarget(targetFloor);
    }

    @Override
    public String describe() {
        return "car request to floor " + targetFloor;
    }
}
