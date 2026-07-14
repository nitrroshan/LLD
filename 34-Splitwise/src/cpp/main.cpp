#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <string>
#include "User.h"
#include "Group.h"
#include "EqualSplitStrategy.h"
#include "ExactSplitStrategy.h"
#include "PercentSplitStrategy.h"
#include "NotificationObserver.h"

int main() {
    std::cout << "=== Splitwise Demo (C++) ===\n\n";

    User alice("U1", "Alice");
    User bob("U2", "Bob");
    User carol("U3", "Carol");

    Group group("Trip");
    group.add_member(&alice);
    group.add_member(&bob);
    group.add_member(&carol);
    NotificationObserver notifier;
    group.add_observer(&notifier);

    std::vector<User*> all = {&alice, &bob, &carol};

    // 1) Equal split — Alice pays $90 dinner, 3 ways.
    std::cout << "Expense 1 (equal split):\n";
    EqualSplitStrategy equal;
    group.add_expense("Dinner", 90.0, &alice, all, equal);

    // 2) Exact split — Bob pays $60 taxi.
    std::cout << "\nExpense 2 (exact split):\n";
    ExactSplitStrategy exact({{"U1", 20.0}, {"U2", 25.0}, {"U3", 15.0}});
    group.add_expense("Taxi", 60.0, &bob, all, exact);

    // 3) Percentage split — Carol pays $50 tickets.
    std::cout << "\nExpense 3 (percentage split):\n";
    PercentSplitStrategy percent({{"U1", 50.0}, {"U2", 30.0}, {"U3", 20.0}});
    group.add_expense("Tickets", 50.0, &carol, all, percent);

    std::cout << "\n";
    group.show_balances();

    std::cout << "\nSimplified settlements (fewest transactions):\n";
    for (const Settlement& s : group.simplify()) {
        std::cout << "  " << s.from->name() << " pays " << s.to->name()
                  << " $" << std::fixed << std::setprecision(2) << s.amount << "\n";
    }

    return 0;
}
