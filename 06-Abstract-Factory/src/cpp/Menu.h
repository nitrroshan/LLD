#pragma once
#include <iostream>
#include <string>

// Abstract Product — Menu
struct Menu {
    virtual ~Menu() = default;
    virtual void render() const = 0;
    virtual void select(const std::string& item) const = 0;
};

struct WindowsMenu : Menu {
    void render() const override {
        std::cout << "[Windows Menu] Rendering dropdown menu with separator lines.\n";
    }
    void select(const std::string& item) const override {
        std::cout << "[Windows Menu] Selected: " << item << " — Windows style.\n";
    }
};

struct MacMenu : Menu {
    void render() const override {
        std::cout << "[Mac Menu] Rendering translucent menu with vibrancy effect.\n";
    }
    void select(const std::string& item) const override {
        std::cout << "[Mac Menu] Selected: " << item << " — macOS style.\n";
    }
};
