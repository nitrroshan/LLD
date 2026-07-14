#pragma once
#include <vector>
#include "DeliveryAgent.h"
#include "Location.h"

// Strategy — chooses a delivery agent for an order starting at `from`.
class DeliveryAssignmentStrategy {
public:
    virtual ~DeliveryAssignmentStrategy() = default;
    virtual DeliveryAgent* select_agent(const std::vector<DeliveryAgent*>& agents,
                                        const Location& from) const = 0;
};

// Assignment — pick the closest available agent to the restaurant.
class NearestAgentAssignmentStrategy : public DeliveryAssignmentStrategy {
public:
    DeliveryAgent* select_agent(const std::vector<DeliveryAgent*>& agents,
                                const Location& from) const override {
        DeliveryAgent* best = nullptr;
        double best_distance = 1e18;
        for (DeliveryAgent* a : agents) {
            double distance = from.distance_to(a->location());
            if (distance < best_distance) {
                best_distance = distance;
                best = a;
            }
        }
        return best;
    }
};
