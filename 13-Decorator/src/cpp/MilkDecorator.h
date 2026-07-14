#pragma once
#include "CoffeeDecorator.h"

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::unique_ptr<Coffee> wrapped)
        : CoffeeDecorator(std::move(wrapped)) {}

    std::string get_description() const override {
        return wrapped_->get_description() + ", Milk";
    }

    double get_cost() const override {
        return wrapped_->get_cost() + 0.50;
    }
};
