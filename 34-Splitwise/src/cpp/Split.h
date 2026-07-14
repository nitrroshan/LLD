#pragma once
#include "User.h"

// One participant's share of an expense.
struct Split {
    User* user;
    double amount;
};
