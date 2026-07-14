package chapter29;

import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

/**
 * Elevator — moves between floors serving its target stops using the LOOK
 * algorithm, controls its door, and notifies observers on every change.
 */
public class Elevator {
    private final String id;
    private int currentFloor;
    private Direction direction = Direction.UP;
    private ElevatorStatus status = ElevatorStatus.IDLE;
    private final TreeSet<Integer> targets = new TreeSet<>();
    private final Door door = new Door();
    private final List<ElevatorObserver> observers = new ArrayList<>();

    public Elevator(String id, int startFloor) {
        this.id = id;
        this.currentFloor = startFloor;
    }

    public String getId() { return id; }
    public int getCurrentFloor() { return currentFloor; }
    public Direction getDirection() { return direction; }
    public ElevatorStatus getStatus() { return status; }
    public int targetCount() { return targets.size(); }
    public boolean isIdle() { return targets.isEmpty(); }

    public void addTarget(int floor) {
        targets.add(floor);
    }

    public void registerObserver(ElevatorObserver observer) {
        observers.add(observer);
    }

    private void notifyObservers() {
        for (ElevatorObserver observer : observers) {
            observer.update(this);
        }
    }

    /** Advance one tick: arrive at a target, or move one floor toward the next. */
    public void step() {
        if (targets.isEmpty()) {
            if (status != ElevatorStatus.IDLE) {
                status = ElevatorStatus.IDLE;
                direction = Direction.IDLE;
                notifyObservers();
            }
            return;
        }

        if (targets.contains(currentFloor)) {
            arrive();
            return;
        }

        int next = pickNextTarget();
        if (next > currentFloor) {
            currentFloor++;
            direction = Direction.UP;
        } else {
            currentFloor--;
            direction = Direction.DOWN;
        }
        status = ElevatorStatus.MOVING;
        notifyObservers();

        if (targets.contains(currentFloor)) {
            arrive();
        }
    }

    private void arrive() {
        status = ElevatorStatus.DOORS_OPEN;
        door.open();
        System.out.printf("  [%s] arrived at floor %d, doors open%n", id, currentFloor);
        targets.remove(currentFloor);
        notifyObservers();
        door.close();
        if (targets.isEmpty()) {
            status = ElevatorStatus.IDLE;
            direction = Direction.IDLE;
        } else {
            status = ElevatorStatus.MOVING;
        }
    }

    /** LOOK: keep going in the current direction; reverse only when exhausted. */
    private int pickNextTarget() {
        if (direction == Direction.UP) {
            Integer up = targets.ceiling(currentFloor);
            return (up != null) ? up : targets.floor(currentFloor);
        } else {
            Integer down = targets.floor(currentFloor);
            return (down != null) ? down : targets.ceiling(currentFloor);
        }
    }
}
