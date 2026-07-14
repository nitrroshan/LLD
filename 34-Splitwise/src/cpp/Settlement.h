#pragma once
#include "User.h"

// A single settlement produced by simplification: "from pays to amount".
struct Settlement {
    User* from;
    User* to;
    double amount;
};
