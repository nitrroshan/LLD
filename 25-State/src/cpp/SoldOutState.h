#pragma once
#include <iostream>
#include "State.h"
#include "GumballMachine.h"

class SoldOutState : public State {
    GumballMachine& machine_;

public:
    explicit SoldOutState(GumballMachine& machine) : machine_(machine) {}

    void insert_quarter() override {
        std::cout << "  You can't insert a quarter, the machine is sold out\n";
    }
    void eject_quarter() override {
        std::cout << "  You can't eject, you haven't inserted a quarter yet\n";
    }
    void turn_crank() override {
        std::cout << "  You turned, but there are no gumballs\n";
    }
    void dispense() override {
        std::cout << "  No gumball dispensed\n";
    }
    const char* name() const override { return "SoldOut"; }
};
