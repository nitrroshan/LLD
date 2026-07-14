#pragma once
#include <string>
#include <vector>
#include "Split.h"
#include "User.h"

// An amount paid by one user, split among participants.
struct Expense {
    std::string description;
    double amount;
    User* paid_by;
    std::vector<Split> splits;
};
