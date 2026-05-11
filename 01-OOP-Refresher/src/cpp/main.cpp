// ============================================================
// Chapter 01 — OOP Refresher in C++
// Compile: g++ -std=c++17 -o main main.cpp && ./main
//
// Structure mirrors Java: one header per class
//   Animal.h, Dog.h, Cat.h, BankAccount.h,
//   Drawable.h, Circle.h, Rectangle.h, Calculator.h
// ============================================================

#include <iostream>
#include <vector>
#include <memory>

#include "BankAccount.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Drawable.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Calculator.h"

int main() {
    std::cout << "=== ENCAPSULATION ===\n";
    BankAccount account("Alice", 1000);
    account.deposit(500);
    account.withdraw(200);
    account.withdraw(5000);  // should fail
    std::cout << "Balance: " << account.getBalance() << "\n";

    std::cout << "\n=== INHERITANCE & POLYMORPHISM ===\n";
    // Using unique_ptr for polymorphic ownership
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>("Buddy", "Golden Retriever"));
    animals.push_back(std::make_unique<Cat>("Whiskers"));
    animals.push_back(std::make_unique<Dog>("Rex", "German Shepherd"));

    for (const auto& animal : animals) {
        animal->eat();
        animal->makeSound();  // runtime polymorphism via vtable
        std::cout << "\n";
    }

    std::cout << "=== ABSTRACTION (Pure Virtual) ===\n";
    std::vector<std::unique_ptr<Drawable>> drawables;
    drawables.push_back(std::make_unique<Circle>(5));
    drawables.push_back(std::make_unique<Rectangle>(4, 6));

    for (const auto& d : drawables) {
        d->draw();
        std::cout << "Area: " << d->area() << "\n\n";
    }

    std::cout << "=== OVERLOADING (Compile-time Polymorphism) ===\n";
    Calculator calc;
    std::cout << "add(2, 3)       = " << calc.add(2, 3) << "\n";
    std::cout << "add(2.5, 3.5)   = " << calc.add(2.5, 3.5) << "\n";
    std::cout << "add(1, 2, 3)    = " << calc.add(1, 2, 3) << "\n";

    return 0;
}
