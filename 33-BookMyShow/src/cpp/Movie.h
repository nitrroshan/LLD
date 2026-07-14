#pragma once
#include <string>

// A film that can be shown.
class Movie {
    std::string id_;
    std::string title_;
    int duration_minutes_;

public:
    Movie(std::string id, std::string title, int duration_minutes)
        : id_(std::move(id)), title_(std::move(title)), duration_minutes_(duration_minutes) {}

    const std::string& id() const { return id_; }
    const std::string& title() const { return title_; }
    int duration_minutes() const { return duration_minutes_; }
};
