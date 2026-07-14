#pragma once
#include <iostream>

// Subsystem class — the audio amplifier.
class Amplifier {
public:
    void on() { std::cout << "Amplifier on\n"; }
    void off() { std::cout << "Amplifier off\n"; }
    void set_volume(int level) { std::cout << "Amplifier volume set to " << level << "\n"; }
};
