#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "State.h"

// Context — owns the state objects and delegates every action to the current
// one. The constructor (which creates the concrete states) is defined in
// main.cpp, after the concrete state classes are complete.
class GumballMachine {
    std::unique_ptr<State> no_quarter_;
    std::unique_ptr<State> has_quarter_;
    std::unique_ptr<State> sold_;
    std::unique_ptr<State> sold_out_;
    State* current_ = nullptr;
    int count_;

public:
    explicit GumballMachine(int count);   // defined in main.cpp

    void insert_quarter() { current_->insert_quarter(); }
    void eject_quarter()  { current_->eject_quarter(); }
    void turn_crank() {
        current_->turn_crank();
        current_->dispense();
    }

    void set_state(State* state) { current_ = state; }

    void release_ball() {
        if (count_ > 0) {
            std::cout << "  A gumball rolls out...\n";
            count_--;
        }
    }

    int count() const { return count_; }

    State* no_quarter_state() { return no_quarter_.get(); }
    State* has_quarter_state() { return has_quarter_.get(); }
    State* sold_state()        { return sold_.get(); }
    State* sold_out_state()    { return sold_out_.get(); }

    std::string status() const {
        return std::string("[state=") + current_->name() +
               ", gumballs=" + std::to_string(count_) + "]";
    }
};
