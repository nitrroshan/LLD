#pragma once
#include <iostream>

// Subsystem class — the dimmable theater lights.
class TheaterLights {
public:
    void on() { std::cout << "Theater lights on\n"; }
    void dim(int level) { std::cout << "Theater lights dimming to " << level << "%\n"; }
};
