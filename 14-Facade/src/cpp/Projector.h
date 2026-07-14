#pragma once
#include <iostream>

// Subsystem class — the video projector.
class Projector {
public:
    void on() { std::cout << "Projector on\n"; }
    void off() { std::cout << "Projector off\n"; }
    void wide_screen_mode() { std::cout << "Projector in widescreen mode (16:9)\n"; }
};
