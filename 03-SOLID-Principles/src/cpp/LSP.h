#pragma once
#include <iostream>
#include <string>

// LSP — Liskov Substitution Principle
// Subtypes must be substitutable for base types without breaking behavior

namespace lsp {

// GOOD: Separate interfaces for capabilities
struct BirdLike {
    virtual ~BirdLike() = default;
    virtual std::string getName() const = 0;
};

struct Flyable {
    virtual ~Flyable() = default;
    virtual void fly() const = 0;
};

struct Sparrow : BirdLike, Flyable {
    std::string getName() const override { return "Sparrow"; }
    void fly() const override { std::cout << "Sparrow is flying!\n"; }
};

struct PenguinGood : BirdLike {
    std::string getName() const override { return "Penguin"; }
    void swim() const { std::cout << "Penguin is swimming!\n"; }
    // No fly() — Penguin doesn't inherit Flyable
};

inline void makeFly(const Flyable& f) {
    f.fly();  // Only called with things that CAN fly
}

inline void demo() {
    Sparrow sparrow;
    PenguinGood penguin;

    makeFly(sparrow);     // ✅ works
    // makeFly(penguin);  // ❌ won't compile — PenguinGood isn't Flyable
    penguin.swim();       // ✅ penguin does what it can
}

} // namespace lsp
