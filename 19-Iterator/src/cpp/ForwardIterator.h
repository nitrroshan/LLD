#pragma once
#include <vector>
#include "Iterator.h"
#include "Song.h"

// Concrete Iterator — walks the playlist front to back.
class ForwardIterator : public Iterator {
    const std::vector<Song>& songs_;
    std::size_t index_ = 0;

public:
    explicit ForwardIterator(const std::vector<Song>& songs) : songs_(songs) {}

    bool has_next() const override {
        return index_ < songs_.size();
    }

    Song next() override {
        return songs_[index_++];
    }
};
