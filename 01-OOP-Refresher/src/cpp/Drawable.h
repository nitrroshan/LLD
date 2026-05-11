#pragma once
#include <iostream>

// Pure virtual class = abstract (like Java interface)
class Drawable {
public:
    virtual ~Drawable() = default;
    virtual void draw() const = 0;
    virtual double area() const = 0;
};
