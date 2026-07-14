#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Notifiable.h"

class Loan;  // forward declaration — member holds non-owning loan pointers

// Abstract borrower. Subclasses define borrowing policy. Implements Notifiable
// so the library can push messages (Observer).
class Member : public Notifiable {
    std::string id_;
    std::string name_;
    std::vector<Loan*> loans_;

public:
    Member(std::string id, std::string name)
        : id_(std::move(id)), name_(std::move(name)) {}

    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }

    virtual int max_books() const = 0;
    virtual int loan_period_days() const = 0;

    int loan_count() const { return static_cast<int>(loans_.size()); }
    void add_loan(Loan* loan) { loans_.push_back(loan); }
    void remove_loan(Loan* loan) {
        loans_.erase(std::remove(loans_.begin(), loans_.end(), loan), loans_.end());
    }

    void on_notify(const std::string& message) override {
        std::cout << "    [Notify " << name_ << "] " << message << "\n";
    }
};
