#pragma once
#include "Book.h"

// Inheritance: DigitalBook --|> Book
class DigitalBook : public Book {
private:
    std::string format;
    double fileSizeMb;

public:
    DigitalBook(const std::string& title, const std::string& isbn, Author* author,
                const std::string& format, double fileSizeMb)
        : Book(title, isbn, author), format(format), fileSizeMb(fileSizeMb) {}

    std::string getFormat() const { return format; }
    double getFileSizeMb() const { return fileSizeMb; }

    void displayInfo() const override {
        std::cout << "[DigitalBook] " << getTitle() << " by " << getAuthor()->getName()
                  << " | Format: " << format << " | Size: " << fileSizeMb << "MB\n";
    }
};
