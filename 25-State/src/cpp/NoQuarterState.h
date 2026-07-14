#pragma once
#include <iostream>
#include "State.h"
#include "GumballMachine.h"

class NoQuarterState : public State {
    GumballMachine& machine_;

public:
    explicit NoQuarterState(GumballMachine& machine) : machine_(machine) {}

    void insert_quarter() override {
        std::cout << "  You inserted a quarter\n";
        machine_.set_state(machine_.has_quarter_state());
    }
    void eject_quarter() override {
        std::cout << "  You haven't inserted a quarter\n";
    }
    void turn_crank() override {
        std::cout << "  You turned, but there's no quarter\n";
    }
    void dispense() override {
        std::cout << "  You need to pay first\n";
    }
    const char* name() const override { return "NoQuarter"; }
};
