#pragma once
#include "BankAccount.h"

// TODO: Inherit from BankAccount (public)
// TODO: Add private field: overdraftLimit (double)
// TODO: Constructor that takes accountNumber, holderName, balance, overdraftLimit
// TODO: Implement getAccountType() → return "Current"
// TODO: Override withdraw() → allow withdrawal up to (balance + overdraftLimit)

class CurrentAccount : public BankAccount {

};
