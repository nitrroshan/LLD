#pragma once
#include <string>
#include <iostream>
#include "Observer.h"

// Concrete Observer — a phone app that shows the temperature.
class PhoneDisplay : public Observer {
    std::string name_;

public:
    explicit PhoneDisplay(std::string name) : name_(std::move(name)) {}

    void update(float temperature) override {
        std::cout << "  [Phone " << name_ << "] It's now " << temperature << " C\n";
    }
};
