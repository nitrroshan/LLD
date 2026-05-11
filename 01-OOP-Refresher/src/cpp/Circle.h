#pragma once
#include "Drawable.h"
#include <cmath>

class Circle : public Drawable {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    void draw() const override {
        std::cout << "Drawing Circle with radius " << radius << "\n";
    }

    double area() const override {
        return M_PI * radius * radius;
    }
};
