package chapter40;

import java.util.List;

/**
 * Strategy — chooses a delivery agent for an order starting at `from`.
 */
public interface DeliveryAssignmentStrategy {
    DeliveryAgent selectAgent(List<DeliveryAgent> agents, Location from);
}
