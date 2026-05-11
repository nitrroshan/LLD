#pragma once
#include <iostream>

// Abstract Product — Checkbox
struct Checkbox {
    virtual ~Checkbox() = default;
    virtual void render() const = 0;
    virtual void toggle() const = 0;
};

struct WindowsCheckbox : Checkbox {
    void render() const override {
        std::cout << "[Windows Checkbox] Rendering square checkbox with checkmark.\n";
    }
    void toggle() const override {
        std::cout << "[Windows Checkbox] Toggled — Windows style.\n";
    }
};

struct MacCheckbox : Checkbox {
    void render() const override {
        std::cout << "[Mac Checkbox] Rendering rounded checkbox with smooth animation.\n";
    }
    void toggle() const override {
        std::cout << "[Mac Checkbox] Toggled — macOS style.\n";
    }
};
