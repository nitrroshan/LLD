#pragma once
#include <vector>
#include "Iterator.h"
#include "Song.h"

// Concrete Iterator — walks the playlist back to front.
class ReverseIterator : public Iterator {
    const std::vector<Song>& songs_;
    long index_;

public:
    explicit ReverseIterator(const std::vector<Song>& songs)
        : songs_(songs), index_(static_cast<long>(songs.size()) - 1) {}

    bool has_next() const override {
        return index_ >= 0;
    }

    Song next() override {
        return songs_[static_cast<std::size_t>(index_--)];
    }
};
