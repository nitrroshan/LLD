#pragma once
#include <cmath>
#include <string>

// A 2D location. Distance is Euclidean "km" for a deterministic demo.
struct Location {
    double x = 0;
    double y = 0;

    Location() = default;
    Location(double x, double y) : x(x), y(y) {}

    double distance_to(const Location& other) const {
        double dx = x - other.x, dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};
