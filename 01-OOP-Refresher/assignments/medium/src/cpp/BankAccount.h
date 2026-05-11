#pragma once
#include "Transferable.h"
#include <string>
#include <iostream>

// TODO: Make this class abstract
// TODO: Inherit from Transferable (public)
// TODO: Add private fields: accountNumber (std::string), holderName (std::string), balance (double)
// TODO: Constructor that takes accountNumber, holderName, balance
// TODO: Getters for all fields
// TODO: deposit(double amount) — validate amount > 0, update balance, print result
// TODO: withdraw(double amount) — validate sufficient balance, update balance, print result (virtual)
// TODO: Pure virtual method: std::string getAccountType() const
// TODO: Implement transfer() from Transferable
//       → withdraw from this, deposit into destination, return true/false
// TODO: displayAccount() const
//       → print: "[<type>] <accountNumber> | <holderName> | Balance: <balance>"
// TODO: Virtual destructor

class BankAccount : public Transferable {

};
