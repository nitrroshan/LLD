#pragma once
#include <string>
#include <memory>
#include "WeaponBehavior.h"
#include "MovementBehavior.h"

// Composed character — mix and match behaviors, swap at runtime
class GameCharacter {
    std::string name;
    std::unique_ptr<WeaponBehavior> weapon;
    std::unique_ptr<MovementBehavior> movement;

public:
    GameCharacter(const std::string& name,
                  std::unique_ptr<WeaponBehavior> weapon,
                  std::unique_ptr<MovementBehavior> movement)
        : name(name), weapon(std::move(weapon)), movement(std::move(movement)) {}

    void attack() const { weapon->attack(name); }
    void move() const { movement->move(name); }

    void setWeapon(std::unique_ptr<WeaponBehavior> w) { weapon = std::move(w); }
    void setMovement(std::unique_ptr<MovementBehavior> m) { movement = std::move(m); }

    const std::string& getName() const { return name; }
};
