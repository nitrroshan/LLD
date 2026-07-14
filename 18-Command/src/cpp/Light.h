#pragma once
#include <string>
#include <iostream>

// Receiver — knows how to perform the real work.
class Light {
    std::string location_;

public:
    explicit Light(std::string location) : location_(std::move(location)) {}

    void on() {
        std::cout << "  " << location_ << " light is ON\n";
    }

    void off() {
        std::cout << "  " << location_ << " light is OFF\n";
    }
};
