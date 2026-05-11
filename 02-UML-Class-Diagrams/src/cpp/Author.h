#pragma once
#include <string>

// Association target: Book --> Author
// Author exists independently of Book
class Author {
private:
    std::string name;
    std::string email;

public:
    Author(const std::string& name, const std::string& email)
        : name(name), email(email) {}

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};
