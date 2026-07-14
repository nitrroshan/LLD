#pragma once
#include <string>

// Command — a transaction encapsulated as an object with execute(). The ATM
// invokes them uniformly, so new transaction types are additive and auditable.
class Transaction {
public:
    virtual ~Transaction() = default;
    virtual void execute() = 0;
    virtual std::string description() const = 0;
};
