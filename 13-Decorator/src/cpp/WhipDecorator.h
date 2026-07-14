#pragma once
#include "CoffeeDecorator.h"

class WhipDecorator : public CoffeeDecorator {
public:
    WhipDecorator(std::unique_ptr<Coffee> wrapped)
        : CoffeeDecorator(std::move(wrapped)) {}

    std::string get_description() const override {
        return wrapped_->get_description() + ", Whip";
    }

    double get_cost() const override {
        return wrapped_->get_cost() + 0.70;
    }
};
