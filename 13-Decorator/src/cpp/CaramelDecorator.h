#pragma once
#include "CoffeeDecorator.h"

class CaramelDecorator : public CoffeeDecorator {
public:
    CaramelDecorator(std::unique_ptr<Coffee> wrapped)
        : CoffeeDecorator(std::move(wrapped)) {}

    std::string get_description() const override {
        return wrapped_->get_description() + ", Caramel";
    }

    double get_cost() const override {
        return wrapped_->get_cost() + 0.60;
    }
};
