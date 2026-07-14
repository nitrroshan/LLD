#pragma once
#include <string>
#include <vector>
#include "Screen.h"

// A venue with one or more screens.
class Theater {
    std::string id_;
    std::string name_;
    std::vector<Screen*> screens_;   // non-owning; screens owned externally

public:
    Theater(std::string id, std::string name)
        : id_(std::move(id)), name_(std::move(name)) {}

    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }

    void add_screen(Screen* screen) { screens_.push_back(screen); }
    const std::vector<Screen*>& screens() const { return screens_; }
};
