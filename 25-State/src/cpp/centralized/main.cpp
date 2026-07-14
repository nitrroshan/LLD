#include <iostream>
#include "GumballMachine.h"

// Same demo as the distributed version, but all transition logic is centralized
// in the machine (the "context decides" approach).
int main() {
    std::cout << "=== State Pattern Demo (Centralized / context-decides, C++) ===\n\n";

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

    std::cout << "\nSame behavior as the distributed version -\n";
    std::cout << "but every transition rule lives in the context, not in state objects.\n";

    return 0;
}
