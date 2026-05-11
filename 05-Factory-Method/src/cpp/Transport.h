#pragma once
#include <iostream>
#include <string>

// Product interface
struct Transport {
    virtual ~Transport() = default;
    virtual void deliver() const = 0;
    virtual std::string getName() const = 0;
};

struct Truck : Transport {
    void deliver() const override { std::cout << "Delivering by land in a truck.\n"; }
    std::string getName() const override { return "Truck"; }
};

struct Ship : Transport {
    void deliver() const override { std::cout << "Delivering by sea in a container ship.\n"; }
    std::string getName() const override { return "Ship"; }
};

struct Airplane : Transport {
    void deliver() const override { std::cout << "Delivering by air in a cargo airplane.\n"; }
    std::string getName() const override { return "Airplane"; }
};
