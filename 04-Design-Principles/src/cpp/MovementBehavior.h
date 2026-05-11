#pragma once
#include <iostream>
#include <string>

struct MovementBehavior {
    virtual ~MovementBehavior() = default;
    virtual void move(const std::string& name) const = 0;
};

struct WalkMovement : MovementBehavior {
    void move(const std::string& name) const override {
        std::cout << name << " walks.\n";
    }
};

struct FlyMovement : MovementBehavior {
    void move(const std::string& name) const override {
        std::cout << name << " flies!\n";
    }
};

struct TeleportMovement : MovementBehavior {
    void move(const std::string& name) const override {
        std::cout << name << " teleports!\n";
    }
};
