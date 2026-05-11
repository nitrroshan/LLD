#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}

    void makeSound() const override {
        std::cout << getName() << " says Meow!\n";
    }

    void purr() const {
        std::cout << getName() << " is purring...\n";
    }
};
