#pragma once
#include <string>

// The element stored in the collection.
class Song {
    std::string title_;
    std::string artist_;

public:
    Song(std::string title, std::string artist)
        : title_(std::move(title)), artist_(std::move(artist)) {}

    std::string to_string() const {
        return "\"" + title_ + "\" by " + artist_;
    }
};
