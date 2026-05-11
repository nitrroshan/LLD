#pragma once
#include <iostream>
#include <string>

class Animal {
private:
    std::string name;

public:
    Animal(const std::string& name) : name(name) {}
    virtual ~Animal() = default;

    std::string getName() const { return name; }

    void eat() const {
        std::cout << name << " is eating.\n";
    }

    virtual void makeSound() const {
        std::cout << name << " makes a generic sound.\n";
    }
};
