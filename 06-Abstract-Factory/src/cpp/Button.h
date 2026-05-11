#pragma once
#include <iostream>
#include <string>

// Abstract Product — Button
struct Button {
    virtual ~Button() = default;
    virtual void render() const = 0;
    virtual void onClick() const = 0;
};

struct WindowsButton : Button {
    void render() const override {
        std::cout << "[Windows Button] Rendering flat-style button with sharp corners.\n";
    }
    void onClick() const override {
        std::cout << "[Windows Button] Click — executing Windows command.\n";
    }
};

struct MacButton : Button {
    void render() const override {
        std::cout << "[Mac Button] Rendering rounded Aqua-style button.\n";
    }
    void onClick() const override {
        std::cout << "[Mac Button] Click — executing macOS command.\n";
    }
};
