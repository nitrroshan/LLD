// Chapter 04 — Design Principles Beyond SOLID in C++
// Compile: g++ -std=c++17 -o main main.cpp && ./main

#include <iostream>
#include <memory>
#include "GameCharacter.h"

int main() {
    std::cout << "=== Composition over Inheritance ===\n\n";

    auto knight = GameCharacter("Arthur",
        std::make_unique<SwordWeapon>(), std::make_unique<WalkMovement>());
    knight.attack();
    knight.move();

    std::cout << "\n";
    auto mage = GameCharacter("Gandalf",
        std::make_unique<MagicWeapon>(), std::make_unique<TeleportMovement>());
    mage.attack();
    mage.move();

    std::cout << "\n--- Runtime Swap ---\n";
    std::cout << knight.getName() << " picks up a bow and learns to fly!\n\n";
    knight.setWeapon(std::make_unique<BowWeapon>());
    knight.setMovement(std::make_unique<FlyMovement>());
    knight.attack();
    knight.move();

    return 0;
}
