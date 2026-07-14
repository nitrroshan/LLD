#pragma once
#include <memory>
#include "TreeType.h"

// Context — stores extrinsic (unique) state (x, y) plus a shared pointer
// to the flyweight. Many trees share the same TreeType.
class Tree {
    int x_;
    int y_;
    std::shared_ptr<const TreeType> type_;

public:
    Tree(int x, int y, std::shared_ptr<const TreeType> type)
        : x_(x), y_(y), type_(std::move(type)) {}

    void draw() const {
        type_->draw(x_, y_);
    }
};
