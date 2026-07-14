#pragma once
#include <string>
#include "BookStatus.h"

// A single physical copy of a book, identified by a barcode.
class BookItem {
    std::string barcode_;
    std::string isbn_;
    BookStatus status_ = BookStatus::Available;
    int due_day_ = 0;

public:
    BookItem(std::string barcode, std::string isbn)
        : barcode_(std::move(barcode)), isbn_(std::move(isbn)) {}

    const std::string& barcode() const { return barcode_; }
    const std::string& isbn() const { return isbn_; }
    BookStatus status() const { return status_; }
    void set_status(BookStatus status) { status_ = status; }
    int due_day() const { return due_day_; }
    void set_due_day(int due_day) { due_day_ = due_day; }
};
