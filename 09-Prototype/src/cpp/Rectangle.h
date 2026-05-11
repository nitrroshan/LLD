#pragma once
#include "Shape.h"

class Rectangle : public Shape {
private:
    int width_;
    int height_;

public:
    Rectangle(int x, int y, const std::string& color, int width, int height)
        : Shape(x, y, color), width_(width), height_(height) {}

    // Copy constructor
    Rectangle(const Rectangle& source)
        : Shape(source), width_(source.width_), height_(source.height_) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }

    int width() const { return width_; }
    int height() const { return height_; }

    std::string to_string() const override {
        return "Rectangle [" + std::to_string(width_) + "x" + std::to_string(height_)
               + " " + Shape::to_string() + "]";
    }
};
