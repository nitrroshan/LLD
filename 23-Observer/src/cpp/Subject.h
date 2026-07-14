#pragma once
#include "Observer.h"

// Subject — maintains the observer list and notifies them of changes.
class Subject {
public:
    virtual ~Subject() = default;
    virtual void register_observer(Observer* observer) = 0;
    virtual void remove_observer(Observer* observer) = 0;
    virtual void notify_observers() = 0;
};
