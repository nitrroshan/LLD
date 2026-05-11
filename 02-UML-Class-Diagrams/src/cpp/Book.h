#pragma once
#include <iostream>
#include <string>
#include "Author.h"

// Composition target: Library *-- Book (Library owns Books)
// Association source: Book --> Author (Book knows Author)
class Book {
private:
    std::string title;
    std::string isbn;
    Author* author;  // Association: pointer — doesn't own Author's lifecycle

public:
    Book(const std::string& title, const std::string& isbn, Author* author)
        : title(title), isbn(isbn), author(author) {}

    virtual ~Book() = default;  // virtual — DigitalBook inherits from this

    std::string getTitle() const { return title; }
    std::string getIsbn() const { return isbn; }
    Author* getAuthor() const { return author; }

    virtual void displayInfo() const {
        std::cout << "[Book] " << title << " by " << author->getName()
                  << " (ISBN: " << isbn << ")\n";
    }
};
