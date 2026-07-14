#pragma once

class Member;
class BookItem;

// An active borrowing: who has which copy, and when it's due.
class Loan {
    Member* member_;
    BookItem* item_;
    int issue_day_;
    int due_day_;

public:
    Loan(Member* member, BookItem* item, int issue_day, int due_day)
        : member_(member), item_(item), issue_day_(issue_day), due_day_(due_day) {}

    Member* member() const { return member_; }
    BookItem* item() const { return item_; }
    int issue_day() const { return issue_day_; }
    int due_day() const { return due_day_; }
};
