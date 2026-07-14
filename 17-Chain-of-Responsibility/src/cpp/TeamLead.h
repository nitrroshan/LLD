#pragma once
#include <iostream>
#include "Approver.h"

class TeamLead : public Approver {
public:
    TeamLead() : Approver("Team Lead", 1000) {}

protected:
    void approve(const PurchaseRequest& request) override {
        std::cout << "  " << name_ << " approved $" << request.amount()
                  << " for " << request.purpose() << "\n";
    }
};
