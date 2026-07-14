#pragma once
#include <iostream>
#include "State.h"
#include "GumballMachine.h"

class SoldState : public State {
    GumballMachine& machine_;

public:
    explicit SoldState(GumballMachine& machine) : machine_(machine) {}

    void insert_quarter() override {
        std::cout << "  Please wait, we're already giving you a gumball\n";
    }
    void eject_quarter() override {
        std::cout << "  Sorry, you already turned the crank\n";
    }
    void turn_crank() override {
        std::cout << "  Turning twice doesn't get you another gumball\n";
    }
    void dispense() override {
        machine_.release_ball();
        if (machine_.count() > 0) {
            machine_.set_state(machine_.no_quarter_state());
        } else {
            std::cout << "  Oops, out of gumballs!\n";
            machine_.set_state(machine_.sold_out_state());
        }
    }
    const char* name() const override { return "Sold"; }
};
