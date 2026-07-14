#pragma once

class GumballMachine;  // forward declaration — states receive the context

// State — declares the actions whose behavior depends on the machine's state.
class State {
public:
    virtual ~State() = default;
    virtual void insert_quarter() = 0;
    virtual void eject_quarter() = 0;
    virtual void turn_crank() = 0;
    virtual void dispense() = 0;
    virtual const char* name() const = 0;
};
