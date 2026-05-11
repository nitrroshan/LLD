// Chapter 02 — UML & Class Diagrams in C++
// Compile: g++ -std=c++17 -o main main.cpp && ./main

#include <iostream>
#include <memory>
#include "Author.h"
#include "Book.h"
#include "DigitalBook.h"
#include "Member.h"
#include "Library.h"

int main() {
    // --- Setup entities ---
    Author author1("Robert C. Martin", "uncle.bob@cleancode.com");
    Author author2("Erich Gamma", "erich@gof.com");

    // --- Composition: Library owns books (unique_ptr = ownership) ---
    Library library("City Library");
    library.addBook(std::make_unique<Book>("Clean Code", "978-0132350884", &author1));
    library.addBook(std::make_unique<Book>("Design Patterns", "978-0201633610", &author2));
    library.addBook(std::make_unique<DigitalBook>("Clean Architecture", "978-0134494166", &author1, "PDF", 12.5));

    // --- Aggregation: Library has members (raw pointers = no ownership) ---
    Member alice("M001", "Alice");
    Member bob("M002", "Bob");
    library.registerMember(&alice);
    library.registerMember(&bob);

    // --- Realization: Library implements Searchable ---
    std::cout << "=== SEARCH (Realization: Library implements Searchable) ===\n";
    Book* found = library.search("Clean Code");
    if (found) {
        std::cout << "Found: " << found->getTitle() << " by " << found->getAuthor()->getName() << "\n";
    }

    auto byAuthor = library.searchByAuthor("Robert C. Martin");
    std::cout << "Books by Robert C. Martin:\n";
    for (auto* b : byAuthor) {
        std::cout << "  - " << b->getTitle() << "\n";
    }

    // --- Dependency: Member uses Book ---
    std::cout << "\n=== BORROW (Dependency: Member uses Book) ===\n";
    alice.borrow(*found);
    bob.borrow(*library.search("Clean Architecture"));

    // --- Inheritance: DigitalBook extends Book ---
    std::cout << "\n=== DIGITAL BOOK (Inheritance) ===\n";
    library.search("Clean Architecture")->displayInfo();

    // --- Library state ---
    std::cout << "\n=== LIBRARY STATE ===\n";
    library.displayInfo();

    return 0;
}
