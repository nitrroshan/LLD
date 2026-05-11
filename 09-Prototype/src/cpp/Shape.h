#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <memory>

class Shape {
protected:
    int x_;
    int y_;
    std::string color_;
    std::vector<std::string> tags_;

public:
    Shape(int x, int y, const std::string& color)
        : x_(x), y_(y), color_(color) {}

    // Copy constructor — deep copies the vector
    Shape(const Shape& source)
        : x_(source.x_), y_(source.y_),
          color_(source.color_), tags_(source.tags_) {}

    virtual ~Shape() = default;

    virtual std::unique_ptr<Shape> clone() const = 0;

    void add_tag(const std::string& tag) { tags_.push_back(tag); }
    void move_to(int x, int y) { x_ = x; y_ = y; }

    virtual std::string to_string() const {
        std::ostringstream oss;
        oss << "(" << x_ << "," << y_ << ") color=" << color_ << " tags=[";
        for (size_t i = 0; i < tags_.size(); ++i) {
            if (i > 0) oss << ", ";
            oss << tags_[i];
        }
        oss << "]";
        return oss.str();
    }
};
