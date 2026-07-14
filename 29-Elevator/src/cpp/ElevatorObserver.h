#pragma once

class Elevator;  // forward declaration

// Observer — notified when an elevator's floor or status changes.
class ElevatorObserver {
public:
    virtual ~ElevatorObserver() = default;
    virtual void update(Elevator& elevator) = 0;
};
