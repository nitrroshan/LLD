#include <iostream>
#include "State.h"
#include "GumballMachine.h"
#include "NoQuarterState.h"
#include "HasQuarterState.h"
#include "SoldState.h"
#include "SoldOutState.h"

// Defined here, where every concrete state class is complete, which breaks
// the GumballMachine <-> concrete-state definition cycle.
GumballMachine::GumballMachine(int count) : count_(count) {
    no_quarter_ = std::make_unique<NoQuarterState>(*this);
    has_quarter_ = std::make_unique<HasQuarterState>(*this);
    sold_ = std::make_unique<SoldState>(*this);
    sold_out_ = std::make_unique<SoldOutState>(*this);
    current_ = count > 0 ? no_quarter_.get() : sold_out_.get();
}

int main() {
    std::cout << "=== State Pattern Demo (C++) ===\n\n";

    GumballMachine machine(2);
    std::cout << machine.status() << "\n";

    std::cout << "\nBuy first gumball:\n";
    machine.insert_quarter();
    machine.turn_crank();
    std::cout << machine.status() << "\n";

    std::cout << "\nBuy second gumball (empties the machine):\n";
    machine.insert_quarter();
    machine.turn_crank();
    std::cout << machine.status() << "\n";

    std::cout << "\nTry to buy when sold out:\n";
    machine.insert_quarter();
    machine.turn_crank();

    std::cout << "\nSame actions behaved differently in each state \u2014\n";
    std::cout << "no conditionals, just the current State object.\n";

    return 0;
}
