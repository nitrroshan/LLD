#pragma once
#include <iostream>

// Subsystem class — the motorized screen.
class Screen {
public:
    void up() { std::cout << "Screen going up\n"; }
    void down() { std::cout << "Screen going down\n"; }
};
