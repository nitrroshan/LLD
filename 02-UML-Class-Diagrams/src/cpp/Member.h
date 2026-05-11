#pragma once
#include <iostream>
#include <string>
#include "Book.h"

// Aggregation: Library o-- Member (exists independently)
// Dependency: Member ..> Book (uses Book in borrow(), doesn't store it)
class Member {
private:
    std::string memberId;
    std::string name;

public:
    Member(const std::string& memberId, const std::string& name)
        : memberId(memberId), name(name) {}

    std::string getMemberId() const { return memberId; }
    std::string getName() const { return name; }

    // Dependency: uses Book as parameter only
    void borrow(const Book& book) const {
        std::cout << name << " borrowed: " << book.getTitle() << "\n";
    }
};
