#pragma once
#include "Drawable.h"

class Rectangle : public Drawable {
private:
    double width, height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    void draw() const override {
        std::cout << "Drawing Rectangle (" << width << " x " << height << ")\n";
    }

    double area() const override {
        return width * height;
    }
};
