package chapter29;

/**
 * The elevator's operating state. Modeled as an enum here; refactoring this
 * into State-pattern classes (Ch25) is the easy assignment.
 */
public enum ElevatorStatus {
    IDLE,
    MOVING,
    DOORS_OPEN
}
