#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

// BEFORE — a smelly God class. One long method mixes subtotal calc, a
// switch-on-type for discounts, an inline magic-number tax, and inline receipt
// formatting. Smells: God Class, Long Method, Switch-on-Type, Magic Numbers.
namespace before {

struct Line {
    std::string name;
    double price;
    int qty;
};

class OrderProcessorBefore {
public:
    // customer_type: 0=REGULAR, 1=PREMIUM, 2=VIP (magic ints).
    double process(int customer_type, const std::vector<Line>& lines) {
        double subtotal = 0;
        for (const auto& l : lines) subtotal += l.price * l.qty;

        // Discount: a switch on a type code (the classic smell).
        double discount;
        if (customer_type == 0)      discount = 0;
        else if (customer_type == 1) discount = subtotal * 0.10;
        else if (customer_type == 2) discount = subtotal * 0.20;
        else                         discount = 0;

        double taxed = (subtotal - discount) * 1.08;   // inline tax + magic number

        // Inline receipt formatting — presentation tangled with calculation.
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "  [before] === RECEIPT ===\n";
        for (const auto& l : lines)
            std::cout << "  [before] " << l.name << " x" << l.qty << " = " << (l.price * l.qty) << "\n";
        std::cout << "  [before] subtotal=" << subtotal << " discount=" << discount
                  << " total=" << taxed << "\n";
        return taxed;
    }
};

} // namespace before
