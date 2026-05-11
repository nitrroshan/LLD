// Chapter 06 — Abstract Factory Pattern in C++
// Compile: g++ -std=c++17 -o main main.cpp && ./main

#include <iostream>
#include <memory>
#include "UIFactory.h"

// Client function — works with UIFactory interface only
void buildUI(const UIFactory& factory) {
    auto button = factory.createButton();
    auto checkbox = factory.createCheckbox();
    auto menu = factory.createMenu();

    std::cout << "--- Rendering UI ---\n";
    button->render();
    checkbox->render();
    menu->render();

    std::cout << "--- Interacting ---\n";
    button->onClick();
    checkbox->toggle();
    menu->select("File > Save");
}

int main() {
    std::cout << "=== Windows UI ===\n";
    WindowsFactory windowsFactory;
    buildUI(windowsFactory);

    std::cout << "\n=== Mac UI ===\n";
    MacFactory macFactory;
    buildUI(macFactory);

    // Runtime family selection
    std::cout << "\n=== Runtime Selection (simulated) ===\n";
    std::string os = "mac";
    std::unique_ptr<UIFactory> factory;
    if (os == "windows") {
        factory = std::make_unique<WindowsFactory>();
    } else {
        factory = std::make_unique<MacFactory>();
    }
    buildUI(*factory);

    return 0;
}
