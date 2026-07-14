#pragma once
#include <vector>
#include <memory>
#include "Song.h"
#include "Iterator.h"
#include "ForwardIterator.h"
#include "ReverseIterator.h"

// Aggregate — stores songs and vends iterators so clients never touch
// the internal vector.
class Playlist {
    std::vector<Song> songs_;

public:
    void add_song(const Song& song) {
        songs_.push_back(song);
    }

    std::unique_ptr<Iterator> iterator() const {
        return std::make_unique<ForwardIterator>(songs_);
    }

    std::unique_ptr<Iterator> reverse_iterator() const {
        return std::make_unique<ReverseIterator>(songs_);
    }
};
