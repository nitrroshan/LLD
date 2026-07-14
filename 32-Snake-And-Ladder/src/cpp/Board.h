#pragma once
#include <memory>
#include <unordered_map>
#include "Jump.h"

// The board: a size plus a map from a cell to the jump that starts there.
class Board {
    int size_;
    std::unordered_map<int, std::unique_ptr<Jump>> jumps_;

public:
    explicit Board(int size) : size_(size) {}

    int size() const { return size_; }

    void add_jump(std::unique_ptr<Jump> jump) {
        int start = jump->start();
        jumps_[start] = std::move(jump);
    }

    // Returns the jump starting at this cell, or nullptr if none.
    Jump* get_jump(int cell) const {
        auto it = jumps_.find(cell);
        return it != jumps_.end() ? it->second.get() : nullptr;
    }
};
