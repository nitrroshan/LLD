#pragma once
#include <string>

// Component interface
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual std::string get_description() const = 0;
    virtual double get_cost() const = 0;
};
