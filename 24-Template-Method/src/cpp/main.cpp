#include <iostream>
#include "Tea.h"
#include "Coffee.h"
#include "BlackCoffee.h"

int main() {
    std::cout << "=== Template Method Pattern Demo (C++) ===\n\n";

    std::cout << "Making tea:\n";
    Tea().prepare_recipe();

    std::cout << "\nMaking coffee:\n";
    Coffee().prepare_recipe();

    std::cout << "\nMaking black coffee (hook skips condiments):\n";
    BlackCoffee().prepare_recipe();

    std::cout << "\nEvery beverage followed the SAME fixed sequence \u2014\n";
    std::cout << "only the brew and condiment steps varied.\n";

    return 0;
}
