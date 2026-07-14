#pragma once
#include <iostream>
#include "Approver.h"

class Director : public Approver {
public:
    Director() : Approver("Director", 20000) {}

protected:
    void approve(const PurchaseRequest& request) override {
        std::cout << "  " << name_ << " approved $" << request.amount()
                  << " for " << request.purpose() << "\n";
    }
};
