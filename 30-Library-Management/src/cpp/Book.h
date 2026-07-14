#pragma once
#include <string>
#include <vector>
#include <memory>
#include "BookItem.h"

// A catalog entry (title) that owns its physical copies.
class Book {
    std::string isbn_;
    std::string title_;
    std::string author_;
    std::vector<std::unique_ptr<BookItem>> items_;

public:
    Book(std::string isbn, std::string title, std::string author)
        : isbn_(std::move(isbn)), title_(std::move(title)), author_(std::move(author)) {}

    const std::string& isbn() const { return isbn_; }
    const std::string& title() const { return title_; }
    const std::string& author() const { return author_; }

    void add_item(std::unique_ptr<BookItem> item) {
        items_.push_back(std::move(item));
    }

    BookItem* find_available_item() {
        for (auto& item : items_) {
            if (item->status() == BookStatus::Available) {
                return item.get();
            }
        }
        return nullptr;
    }

    int available_count() const {
        int count = 0;
        for (const auto& item : items_) {
            if (item->status() == BookStatus::Available) {
                count++;
            }
        }
        return count;
    }

    int total_count() const { return static_cast<int>(items_.size()); }
};
