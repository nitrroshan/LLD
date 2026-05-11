#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
    int radius_;

public:
    Circle(int x, int y, const std::string& color, int radius)
        : Shape(x, y, color), radius_(radius) {}

    // Copy constructor
    Circle(const Circle& source) : Shape(source), radius_(source.radius_) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }

    int radius() const { return radius_; }

    std::string to_string() const override {
        return "Circle [radius=" + std::to_string(radius_) + " " + Shape::to_string() + "]";
    }
};
