#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "PurchaseRequest.h"

// Handler — holds the next link (owned) and provides the forwarding logic.
// Subclasses only implement approve().
class Approver {
protected:
    std::unique_ptr<Approver> next_;
    std::string name_;
    double limit_;

    virtual void approve(const PurchaseRequest& request) = 0;

public:
    Approver(std::string name, double limit)
        : name_(std::move(name)), limit_(limit) {}
    virtual ~Approver() = default;

    // Wire the next handler; returns a raw pointer to it for fluent chaining.
    Approver* set_next(std::unique_ptr<Approver> next) {
        next_ = std::move(next);
        return next_.get();
    }

    void handle(const PurchaseRequest& request) {
        if (request.amount() <= limit_) {
            approve(request);
        } else if (next_) {
            next_->handle(request);
        } else {
            std::cout << "  Request for $" << request.amount() << " ("
                      << request.purpose() << ") could not be approved by anyone.\n";
        }
    }
};
