package chapter40;

import java.util.List;

/**
 * Assignment — pick the closest available agent to the restaurant.
 */
public class NearestAgentAssignmentStrategy implements DeliveryAssignmentStrategy {
    @Override
    public DeliveryAgent selectAgent(List<DeliveryAgent> agents, Location from) {
        DeliveryAgent best = null;
        double bestDistance = Double.MAX_VALUE;
        for (DeliveryAgent agent : agents) {
            double distance = from.distanceTo(agent.location());
            if (distance < bestDistance) {
                bestDistance = distance;
                best = agent;
            }
        }
        return best;
    }
}
