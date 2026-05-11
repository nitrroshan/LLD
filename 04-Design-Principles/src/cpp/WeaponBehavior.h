#pragma once
#include <iostream>
#include <string>
#include <functional>

// Weapon behaviors — each is a standalone, reusable component
struct WeaponBehavior {
    virtual ~WeaponBehavior() = default;
    virtual void attack(const std::string& name) const = 0;
};

struct SwordWeapon : WeaponBehavior {
    void attack(const std::string& name) const override {
        std::cout << name << " swings a sword!\n";
    }
};

struct BowWeapon : WeaponBehavior {
    void attack(const std::string& name) const override {
        std::cout << name << " shoots an arrow!\n";
    }
};

struct MagicWeapon : WeaponBehavior {
    void attack(const std::string& name) const override {
        std::cout << name << " casts a fireball!\n";
    }
};
