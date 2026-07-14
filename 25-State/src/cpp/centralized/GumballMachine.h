#pragma once
#include <string>
#include <iostream>

// Centralized ("context decides") variant of the State pattern.
//
// The STATE is a plain enum and ALL transition logic lives here in the context
// — one switch per action. Compare with the distributed version (parent cpp
// folder), where each State object performs its own transitions.
//
// Trade-offs:
//   + Simpler for small machines; every rule is in one file.
//   + No state<->context back-references.
//   - The context grows as states/actions multiply (conditionals return).
//   - Adding a state means editing every action method (weaker OCP).
class GumballMachine {
public:
    enum class State { NoQuarter, HasQuarter, Sold, SoldOut };

private:
    State state_;
    int count_;

    // Count-dependent transition — exactly what a static transition TABLE
    // cannot express, so it lives in code.
    void dispense() {
        if (state_ != State::Sold) return;
        if (count_ > 0) {
            std::cout << "  A gumball rolls out...\n";
            count_--;
        }
        if (count_ > 0) {
            state_ = State::NoQuarter;
        } else {
            std::cout << "  Oops, out of gumballs!\n";
            state_ = State::SoldOut;
        }
    }

    static const char* name(State s) {
        switch (s) {
            case State::NoQuarter:  return "NO_QUARTER";
            case State::HasQuarter: return "HAS_QUARTER";
            case State::Sold:       return "SOLD";
            case State::SoldOut:    return "SOLD_OUT";
        }
        return "?";
    }

public:
    explicit GumballMachine(int count)
        : state_(count > 0 ? State::NoQuarter : State::SoldOut), count_(count) {}

    void insert_quarter() {
        switch (state_) {
            case State::NoQuarter:
                std::cout << "  You inserted a quarter\n";
                state_ = State::HasQuarter;
                break;
            case State::HasQuarter:
                std::cout << "  You can't insert another quarter\n";
                break;
            case State::Sold:
                std::cout << "  Please wait, we're already giving you a gumball\n";
                break;
            case State::SoldOut:
                std::cout << "  You can't insert a quarter, the machine is sold out\n";
                break;
        }
    }

    void eject_quarter() {
        switch (state_) {
            case State::HasQuarter:
                std::cout << "  Quarter returned\n";
                state_ = State::NoQuarter;
                break;
            case State::NoQuarter:
                std::cout << "  You haven't inserted a quarter\n";
                break;
            case State::Sold:
                std::cout << "  Sorry, you already turned the crank\n";
                break;
            case State::SoldOut:
                std::cout << "  You can't eject, you haven't inserted a quarter yet\n";
                break;
        }
    }

    void turn_crank() {
        switch (state_) {
            case State::HasQuarter:
                std::cout << "  You turned the crank...\n";
                state_ = State::Sold;
                dispense();
                break;
            case State::NoQuarter:
                std::cout << "  You turned, but there's no quarter\n";
                break;
            case State::Sold:
                std::cout << "  Turning twice doesn't get you another gumball\n";
                break;
            case State::SoldOut:
                std::cout << "  You turned, but there are no gumballs\n";
                break;
        }
    }

    std::string status() const {
        return std::string("[state=") + name(state_) +
               ", gumballs=" + std::to_string(count_) + "]";
    }
};
