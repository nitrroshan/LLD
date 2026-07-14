#pragma once
#include "Coffee.h"

class Latte : public Coffee {
public:
    std::string get_description() const override { return "Latte"; }
    double get_cost() const override { return 3.00; }
};
