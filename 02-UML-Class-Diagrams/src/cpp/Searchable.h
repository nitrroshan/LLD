#pragma once
#include <string>
#include <vector>
#include "Book.h"

// Realization: Library implements Searchable
// In C++, interfaces are pure virtual classes
class Searchable {
public:
    virtual ~Searchable() = default;
    virtual Book* search(const std::string& title) = 0;
    virtual std::vector<Book*> searchByAuthor(const std::string& authorName) = 0;
};
