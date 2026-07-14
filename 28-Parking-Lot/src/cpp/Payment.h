#pragma once
#include <iostream>
#include <iomanip>

// Processes the computed fee.
class Payment {
    double amount_;
    bool completed_ = false;

public:
    explicit Payment(double amount) : amount_(amount) {}

    void process() {
        completed_ = true;
        std::cout << "  Payment of $" << std::fixed << std::setprecision(2)
                  << amount_ << " processed\n";
    }

    double amount() const { return amount_; }
    bool completed() const { return completed_; }
};
