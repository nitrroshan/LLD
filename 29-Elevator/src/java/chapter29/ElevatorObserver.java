package chapter29;

/**
 * Observer — notified when an elevator's floor or status changes.
 */
public interface ElevatorObserver {
    void update(Elevator elevator);
}
