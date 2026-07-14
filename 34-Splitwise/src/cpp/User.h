#pragma once
#include <string>

// A person who shares expenses. Identity is the object itself (used as a key).
class User {
    std::string id_;
    std::string name_;

public:
    User(std::string id, std::string name) : id_(std::move(id)), name_(std::move(name)) {}
    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }
};
