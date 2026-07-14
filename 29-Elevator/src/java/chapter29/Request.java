package chapter29;

/**
 * Command — a call encapsulated as an object. executeOn applies the request to
 * a chosen elevator (adds the stop). Requests can be queued, logged, or replayed.
 */
public interface Request {
    int floor();
    Direction direction();
    void executeOn(Elevator elevator);
    String describe();
}
