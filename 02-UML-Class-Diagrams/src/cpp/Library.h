#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Book.h"
#include "Member.h"
#include "Searchable.h"

// Composition: Library *-- Book (owns Books via unique_ptr)
// Aggregation: Library o-- Member (has Members via raw pointer — doesn't own)
// Realization: Library implements Searchable
class Library : public Searchable {
private:
    std::string name;
    std::vector<std::unique_ptr<Book>> books;   // Composition: owns lifecycle
    std::vector<Member*> members;               // Aggregation: doesn't own lifecycle

public:
    Library(const std::string& name) : name(name) {}

    // Composition: Library creates and owns books
    void addBook(std::unique_ptr<Book> book) {
        books.push_back(std::move(book));
    }

    // Aggregation: Library registers members it doesn't own
    void registerMember(Member* member) {
        members.push_back(member);
    }

    // Realization: implements Searchable
    Book* search(const std::string& title) override {
        for (auto& b : books) {
            if (b->getTitle() == title) return b.get();
        }
        return nullptr;
    }

    std::vector<Book*> searchByAuthor(const std::string& authorName) override {
        std::vector<Book*> results;
        for (auto& b : books) {
            if (b->getAuthor()->getName() == authorName) {
                results.push_back(b.get());
            }
        }
        return results;
    }

    void displayInfo() const {
        std::cout << "Library: " << name << "\n";
        std::cout << "Books (" << books.size() << "):\n";
        for (const auto& b : books) {
            std::cout << "  - " << b->getTitle() << " by " << b->getAuthor()->getName() << "\n";
        }
        std::cout << "Members (" << members.size() << "):\n";
        for (const auto& m : members) {
            std::cout << "  - " << m->getName() << " (" << m->getMemberId() << ")\n";
        }
    }
};
