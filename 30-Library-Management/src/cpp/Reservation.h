#pragma once
#include <string>

class Member;

// A member waiting for a title that is currently all loaned out.
class Reservation {
    Member* member_;
    std::string isbn_;
    int day_;

public:
    Reservation(Member* member, std::string isbn, int day)
        : member_(member), isbn_(std::move(isbn)), day_(day) {}

    Member* member() const { return member_; }
    const std::string& isbn() const { return isbn_; }
    int day() const { return day_; }
};
