#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Book.h"
#include "BookItem.h"
#include "Member.h"
#include "Loan.h"
#include "Reservation.h"
#include "FineStrategy.h"

// Coordinator: manages the catalog and members, and runs the borrow / return /
// reserve workflows. Fines are delegated to a pluggable strategy; members are
// notified through the Notifiable (Observer) interface.
class Library {
    std::unordered_map<std::string, std::unique_ptr<Book>> books_;
    std::unordered_map<std::string, std::unique_ptr<Member>> members_;
    std::unordered_map<std::string, std::unique_ptr<Loan>> active_loans_;   // barcode -> loan
    std::unordered_map<std::string, std::vector<Reservation>> reservations_; // isbn -> queue
    std::unique_ptr<FineStrategy> fine_strategy_;

    void handoff_to_reserver(Book& book, BookItem& item) {
        auto it = reservations_.find(book.isbn());
        if (it != reservations_.end() && !it->second.empty()) {
            Reservation next = it->second.front();
            it->second.erase(it->second.begin());
            item.set_status(BookStatus::Reserved);
            next.member()->on_notify("'" + book.title() + "' is now available for pickup");
        }
    }

public:
    explicit Library(std::unique_ptr<FineStrategy> fine_strategy)
        : fine_strategy_(std::move(fine_strategy)) {}

    void set_fine_strategy(std::unique_ptr<FineStrategy> strategy) {
        fine_strategy_ = std::move(strategy);
    }

    void add_book(std::unique_ptr<Book> book) {
        books_[book->isbn()] = std::move(book);
    }

    void register_member(std::unique_ptr<Member> member) {
        members_[member->id()] = std::move(member);
    }

    std::vector<Book*> search(const std::string& query) {
        std::string q = query;
        std::transform(q.begin(), q.end(), q.begin(), ::tolower);
        std::vector<Book*> results;
        for (auto& entry : books_) {
            std::string title = entry.second->title();
            std::string author = entry.second->author();
            std::transform(title.begin(), title.end(), title.begin(), ::tolower);
            std::transform(author.begin(), author.end(), author.begin(), ::tolower);
            if (title.find(q) != std::string::npos || author.find(q) != std::string::npos) {
                results.push_back(entry.second.get());
            }
        }
        return results;
    }

    void borrow_book(const std::string& member_id, const std::string& isbn, int day) {
        auto mit = members_.find(member_id);
        auto bit = books_.find(isbn);
        if (mit == members_.end() || bit == books_.end()) {
            std::cout << "  Borrow failed: unknown member or book\n";
            return;
        }
        Member* member = mit->second.get();
        Book* book = bit->second.get();
        if (member->loan_count() >= member->max_books()) {
            std::cout << "  " << member->name() << " has reached the borrow limit ("
                      << member->max_books() << ")\n";
            return;
        }
        BookItem* item = book->find_available_item();
        if (!item) {
            std::cout << "  '" << book->title() << "' has no available copy - consider reserving\n";
            return;
        }
        int due_day = day + member->loan_period_days();
        item->set_status(BookStatus::Loaned);
        item->set_due_day(due_day);
        auto loan = std::make_unique<Loan>(member, item, day, due_day);
        member->add_loan(loan.get());
        std::cout << "  " << member->name() << " borrowed '" << book->title()
                  << "' (copy " << item->barcode() << "), due day " << due_day << "\n";
        active_loans_[item->barcode()] = std::move(loan);
    }

    void return_book(const std::string& barcode, int day) {
        auto it = active_loans_.find(barcode);
        if (it == active_loans_.end()) {
            std::cout << "  Return failed: no active loan for " << barcode << "\n";
            return;
        }
        Loan* loan = it->second.get();
        BookItem* item = loan->item();
        Book* book = books_[item->isbn()].get();
        int overdue_days = std::max(0, day - loan->due_day());
        loan->member()->remove_loan(loan);
        item->set_status(BookStatus::Available);
        std::cout << "  " << loan->member()->name() << " returned '" << book->title()
                  << "' (copy " << barcode << ")\n";
        if (overdue_days > 0) {
            double fine = fine_strategy_->calculate_fine(overdue_days);
            std::cout << "    Overdue " << overdue_days << " day(s) -> fine $"
                      << std::fixed << std::setprecision(2) << fine << "\n";
        }
        handoff_to_reserver(*book, *item);
        active_loans_.erase(it);   // destroys the loan last
    }

    void reserve_book(const std::string& member_id, const std::string& isbn, int day) {
        auto mit = members_.find(member_id);
        auto bit = books_.find(isbn);
        if (mit == members_.end() || bit == books_.end()) {
            std::cout << "  Reserve failed: unknown member or book\n";
            return;
        }
        reservations_[isbn].emplace_back(mit->second.get(), isbn, day);
        std::cout << "  " << mit->second->name() << " reserved '" << bit->second->title() << "'\n";
    }

    void send_due_reminders(int day) {
        std::cout << "  Sending due-date reminders:\n";
        for (auto& entry : active_loans_) {
            Loan* loan = entry.second.get();
            int days_left = loan->due_day() - day;
            if (days_left <= 2) {
                Book* book = books_[loan->item()->isbn()].get();
                loan->member()->on_notify(
                    "'" + book->title() + "' is due in " + std::to_string(days_left) + " day(s)");
            }
        }
    }
};
