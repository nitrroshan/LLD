#pragma once
#include <string>
#include "Direction.h"

class Elevator;  // forward declaration

// Command — a call encapsulated as an object. execute_on applies it to a chosen
// elevator. Requests can be queued, logged, or replayed.
class Request {
public:
    virtual ~Request() = default;
    virtual int floor() const = 0;
    virtual Direction direction() const = 0;
    virtual void execute_on(Elevator& elevator) const = 0;
    virtual std::string describe() const = 0;
};
