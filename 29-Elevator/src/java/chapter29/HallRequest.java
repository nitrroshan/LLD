package chapter29;

/**
 * Concrete Command — an external hall call: someone on a floor wants to go a
 * direction. The controller picks which elevator serves it.
 */
public class HallRequest implements Request {
    private final int floor;
    private final Direction direction;

    public HallRequest(int floor, Direction direction) {
        this.floor = floor;
        this.direction = direction;
    }

    @Override
    public int floor() {
        return floor;
    }

    @Override
    public Direction direction() {
        return direction;
    }

    @Override
    public void executeOn(Elevator elevator) {
        elevator.addTarget(floor);
    }

    @Override
    public String describe() {
        return "hall call at floor " + floor + " going " + direction;
    }
}
