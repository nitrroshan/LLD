#pragma once
#include <string>

// A guest who books rooms.
class Guest {
    std::string id_;
    std::string name_;
public:
    Guest(std::string id, std::string name) : id_(std::move(id)), name_(std::move(name)) {}
    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }
};
