#pragma once
#include <iostream>
#include <string>

// Subsystem class — the DVD player.
class DvdPlayer {
public:
    void on() { std::cout << "DVD player on\n"; }
    void off() { std::cout << "DVD player off\n"; }
    void play(const std::string& movie) { std::cout << "Playing \"" << movie << "\"\n"; }
    void stop() { std::cout << "Stopping playback\n"; }
};
