#pragma once
#include <iostream>
#include "CaffeineBeverage.h"

// Concrete Class — fills in the varying steps for coffee.
class Coffee : public CaffeineBeverage {
protected:
    void brew() override {
        std::cout << "  Dripping coffee through filter\n";
    }

    void add_condiments() override {
        std::cout << "  Adding sugar and milk\n";
    }
};
