#pragma once
#include <iostream>
#include <memory>

// OCP — Open/Closed Principle
// Extend behavior by adding new classes, not modifying existing code

namespace ocp {

struct DiscountStrategy {
    virtual ~DiscountStrategy() = default;
    virtual double calculate(double amount) const = 0;
};

struct RegularDiscount : DiscountStrategy {
    double calculate(double amount) const override { return amount * 0.05; }
};

struct PremiumDiscount : DiscountStrategy {
    double calculate(double amount) const override { return amount * 0.10; }
};

struct VIPDiscount : DiscountStrategy {
    double calculate(double amount) const override { return amount * 0.20; }
};

// Adding new discount = new class, nothing else changes
struct EmployeeDiscount : DiscountStrategy {
    double calculate(double amount) const override { return amount * 0.30; }
};

struct DiscountCalculator {
    double calculate(const DiscountStrategy& strategy, double amount) const {
        return strategy.calculate(amount);
    }
};

inline void demo() {
    DiscountCalculator calc;
    double amount = 1000;
    std::cout << "Regular:  $" << calc.calculate(RegularDiscount{}, amount) << "\n";
    std::cout << "Premium:  $" << calc.calculate(PremiumDiscount{}, amount) << "\n";
    std::cout << "VIP:      $" << calc.calculate(VIPDiscount{}, amount) << "\n";
    std::cout << "Employee: $" << calc.calculate(EmployeeDiscount{}, amount) << "\n";
}

} // namespace ocp
