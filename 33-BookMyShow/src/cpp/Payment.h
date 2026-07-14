#pragma once
#include <iostream>
#include <iomanip>

// Processes a charge. Minimal stand-in for a real payment gateway.
class Payment {
    double amount_;
    bool success_ = false;

public:
    explicit Payment(double amount) : amount_(amount) {}

    bool process() {
        success_ = true;   // a real gateway could decline
        std::cout << "    Charged $" << std::fixed << std::setprecision(2) << amount_ << "\n";
        return success_;
    }

    double amount() const { return amount_; }
    bool success() const { return success_; }
};
