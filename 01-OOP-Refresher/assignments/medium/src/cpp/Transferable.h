#pragma once
#include <string>

// TODO: Define this as a pure interface (abstract class with only pure virtual methods)
// Method: virtual bool transfer(class BankAccount& destination, double amount) = 0

class Transferable {
public:
    virtual ~Transferable() = default;
};
