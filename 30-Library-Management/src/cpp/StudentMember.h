#pragma once
#include "Member.h"

// Student policy: up to 3 books for 14 days.
class StudentMember : public Member {
public:
    StudentMember(std::string id, std::string name) : Member(std::move(id), std::move(name)) {}
    int max_books() const override { return 3; }
    int loan_period_days() const override { return 14; }
};
