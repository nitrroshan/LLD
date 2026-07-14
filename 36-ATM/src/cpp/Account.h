#pragma once
#include <string>
#include <utility>

// An account held by the bank. Owns the balance and verifies its own PIN.
class Account {
    std::string account_number_;
    std::string pin_;
    int balance_; // whole dollars

public:
    Account(std::string account_number, std::string pin, int balance)
        : account_number_(std::move(account_number)), pin_(std::move(pin)), balance_(balance) {}

    const std::string& account_number() const { return account_number_; }
    bool verify_pin(const std::string& candidate) const { return pin_ == candidate; }
    int balance() const { return balance_; }
    void debit(int amount) { balance_ -= amount; }
    void credit(int amount) { balance_ += amount; }
};
