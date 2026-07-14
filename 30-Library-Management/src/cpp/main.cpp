#include <iostream>
#include <memory>
#include <vector>
#include "Library.h"
#include "Book.h"
#include "BookItem.h"
#include "MemberFactory.h"
#include "FlatPerDayFineStrategy.h"
#include "TieredFineStrategy.h"

int main() {
    std::cout << "=== Library Management System Demo (C++) ===\n\n";

    // Fine policy is a Strategy — start with a flat per-day charge.
    Library library(std::make_unique<FlatPerDayFineStrategy>(1.50));

    // Catalog: two titles, with copies.
    auto clean = std::make_unique<Book>("111", "Clean Code", "Robert Martin");
    clean->add_item(std::make_unique<BookItem>("C1", "111"));
    clean->add_item(std::make_unique<BookItem>("C2", "111"));
    auto gof = std::make_unique<Book>("222", "Design Patterns", "Gang of Four");
    gof->add_item(std::make_unique<BookItem>("G1", "222"));
    library.add_book(std::move(clean));
    library.add_book(std::move(gof));

    // Members via the factory.
    library.register_member(MemberFactory::create(MemberType::Student, "S1", "Alice"));
    library.register_member(MemberFactory::create(MemberType::Faculty, "F1", "Bob"));

    // Search
    std::cout << "Search 'design':\n";
    for (Book* book : library.search("design")) {
        std::cout << "  " << book->title() << " by " << book->author()
                  << " (" << book->available_count() << "/" << book->total_count() << " available)\n";
    }

    // Borrowing
    std::cout << "\nBorrowing (day 0):\n";
    library.borrow_book("S1", "111", 0);
    library.borrow_book("F1", "222", 0);

    // Reserve a title that's now fully loaned
    std::cout << "\nAlice reserves Design Patterns (all copies out):\n";
    library.reserve_book("S1", "222", 1);

    // Bob returns overdue -> fine, and Alice is notified of her reservation
    std::cout << "\nBob returns Design Patterns late (day 35, due day 30):\n";
    library.return_book("G1", 35);

    // Due-date reminders
    std::cout << "\nAt day 13:\n";
    library.send_due_reminders(13);

    // Swap the fine strategy at runtime
    std::cout << "\nSwitching to a tiered fine policy, Alice returns late (day 20, due 14):\n";
    library.set_fine_strategy(std::make_unique<TieredFineStrategy>(1.0, 3.0, 3));
    library.return_book("C1", 20);   // 6 days overdue: 3*1 + 3*3 = 12.00

    return 0;
}
