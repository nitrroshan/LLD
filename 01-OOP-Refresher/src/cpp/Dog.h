#pragma once
#include "Animal.h"

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& name, const std::string& breed)
        : Animal(name), breed(breed) {}

    std::string getBreed() const { return breed; }

    void makeSound() const override {
        std::cout << getName() << " says Woof! [" << breed << "]\n";
    }

    void fetch() const {
        std::cout << getName() << " fetches the ball!\n";
    }
};
