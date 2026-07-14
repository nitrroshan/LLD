#pragma once
#include <iostream>
#include "Approver.h"

class Manager : public Approver {
public:
    Manager() : Approver("Manager", 5000) {}

protected:
    void approve(const PurchaseRequest& request) override {
        std::cout << "  " << name_ << " approved $" << request.amount()
                  << " for " << request.purpose() << "\n";
    }
};
