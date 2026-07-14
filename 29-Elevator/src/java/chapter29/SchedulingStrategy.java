package chapter29;

import java.util.List;

/**
 * Strategy — chooses which elevator serves a hall call.
 */
public interface SchedulingStrategy {
    Elevator select(List<Elevator> elevators, Request request);
}
