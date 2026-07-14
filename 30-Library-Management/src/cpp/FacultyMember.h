#pragma once
#include "Member.h"

// Faculty policy: up to 10 books for 30 days.
class FacultyMember : public Member {
public:
    FacultyMember(std::string id, std::string name) : Member(std::move(id), std::move(name)) {}
    int max_books() const override { return 10; }
    int loan_period_days() const override { return 30; }
};
