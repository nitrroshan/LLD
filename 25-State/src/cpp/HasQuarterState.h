#pragma once
#include <iostream>
#include "State.h"
#include "GumballMachine.h"

class HasQuarterState : public State {
    GumballMachine& machine_;

public:
    explicit HasQuarterState(GumballMachine& machine) : machine_(machine) {}

    void insert_quarter() override {
        std::cout << "  You can't insert another quarter\n";
    }
    void eject_quarter() override {
        std::cout << "  Quarter returned\n";
        machine_.set_state(machine_.no_quarter_state());
    }
    void turn_crank() override {
        std::cout << "  You turned the crank...\n";
        machine_.set_state(machine_.sold_state());
    }
    void dispense() override {
        std::cout << "  No gumball dispensed\n";
    }
    const char* name() const override { return "HasQuarter"; }
};
