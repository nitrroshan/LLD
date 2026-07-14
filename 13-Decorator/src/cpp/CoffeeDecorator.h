#pragma once
#include "Coffee.h"
#include <memory>

// Abstract Decorator — wraps a Coffee and IS a Coffee
class CoffeeDecorator : public Coffee {
protected:
    std::unique_ptr<Coffee> wrapped_;

public:
    CoffeeDecorator(std::unique_ptr<Coffee> wrapped)
        : wrapped_(std::move(wrapped)) {}
};
