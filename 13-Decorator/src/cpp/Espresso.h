#pragma once
#include "Coffee.h"

class Espresso : public Coffee {
public:
    std::string get_description() const override { return "Espresso"; }
    double get_cost() const override { return 2.00; }
};
