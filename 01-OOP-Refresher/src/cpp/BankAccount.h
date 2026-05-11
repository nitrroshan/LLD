#pragma once
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string& owner, double initialBalance)
        : owner(owner), balance(initialBalance) {}

    double getBalance() const { return balance; }
    std::string getOwner() const { return owner; }

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        std::cout << owner << " deposited " << amount << ". New balance: " << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            std::cout << "Insufficient funds! " << owner << " tried to withdraw "
                      << amount << " but balance is " << balance << "\n";
            return;
        }
        balance -= amount;
        std::cout << owner << " withdrew " << amount << ". New balance: " << balance << "\n";
    }
};
