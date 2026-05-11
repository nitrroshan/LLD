#pragma once
#include <memory>
#include "Button.h"
#include "Checkbox.h"
#include "Menu.h"

// Abstract Factory — creates a consistent family of UI components
class UIFactory {
public:
    virtual ~UIFactory() = default;
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
    virtual std::unique_ptr<Menu> createMenu() const = 0;
};

// Concrete Factory — Windows family
class WindowsFactory : public UIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<WindowsButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<WindowsCheckbox>();
    }
    std::unique_ptr<Menu> createMenu() const override {
        return std::make_unique<WindowsMenu>();
    }
};

// Concrete Factory — Mac family
class MacFactory : public UIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<MacButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<MacCheckbox>();
    }
    std::unique_ptr<Menu> createMenu() const override {
        return std::make_unique<MacMenu>();
    }
};
