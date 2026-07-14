#pragma once
#include <vector>

class Elevator;
class Request;

// Strategy — chooses which elevator serves a hall call.
class SchedulingStrategy {
public:
    virtual ~SchedulingStrategy() = default;
    virtual Elevator* select(const std::vector<Elevator*>& elevators,
                             const Request& request) const = 0;
};
