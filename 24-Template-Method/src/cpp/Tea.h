#pragma once
#include <iostream>
#include "CaffeineBeverage.h"

// Concrete Class — fills in the varying steps for tea.
class Tea : public CaffeineBeverage {
protected:
    void brew() override {
        std::cout << "  Steeping the tea\n";
    }

    void add_condiments() override {
        std::cout << "  Adding lemon\n";
    }
};
