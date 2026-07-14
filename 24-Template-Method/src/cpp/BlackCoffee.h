#pragma once
#include <iostream>
#include "CaffeineBeverage.h"

// Concrete Class — black coffee overrides the hook to skip condiments.
class BlackCoffee : public CaffeineBeverage {
protected:
    void brew() override {
        std::cout << "  Dripping coffee through filter\n";
    }

    void add_condiments() override {
        // no condiments
    }

    bool wants_condiments() override {
        return false;   // hook overridden — condiment step is skipped
    }
};
