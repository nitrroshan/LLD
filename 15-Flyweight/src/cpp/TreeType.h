#pragma once
#include <string>
#include <iostream>

// Flyweight — stores ONLY intrinsic (shared) state. Immutable (const fields).
// Extrinsic state (x, y) is passed IN via draw().
class TreeType {
    const std::string name_;
    const std::string color_;
    const std::string texture_;

public:
    TreeType(std::string name, std::string color, std::string texture)
        : name_(std::move(name)), color_(std::move(color)), texture_(std::move(texture)) {}

    void draw(int x, int y) const {
        std::cout << "  Drawing " << name_ << " (" << color_
                  << ", texture=" << texture_ << ") at ("
                  << x << ", " << y << ")\n";
    }

    const std::string& name() const { return name_; }
};
