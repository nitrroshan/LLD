#pragma once
#include <iostream>
#include <string>

// SRP — Single Responsibility Principle
// BAD: Invoice does calculation + printing + persistence
// GOOD: Each responsibility in its own class

namespace srp {

// --- GOOD ---
struct Invoice {
    std::string product;
    int quantity;
    double pricePerUnit;

    double getTotal() const { return quantity * pricePerUnit; }
};

struct InvoicePrinter {
    void print(const Invoice& inv) const {
        std::cout << "Invoice: " << inv.product << " x" << inv.quantity
                  << " = $" << inv.getTotal() << "\n";
    }
};

struct InvoiceRepository {
    void save(const Invoice& inv) const {
        std::cout << "[DB] Saving invoice for " << inv.product << "\n";
    }
};

inline void demo() {
    Invoice inv{"Keyboard", 2, 49.99};
    InvoicePrinter{}.print(inv);
    InvoiceRepository{}.save(inv);
}

} // namespace srp
