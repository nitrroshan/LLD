package chapter30;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Library Management System Demo ===\n");

        // Fine policy is a Strategy — start with a flat per-day charge.
        Library library = new Library(new FlatPerDayFineStrategy(1.50));

        // Catalog: two titles, with copies.
        Book clean = new Book("111", "Clean Code", "Robert Martin");
        clean.addItem(new BookItem("C1", "111"));
        clean.addItem(new BookItem("C2", "111"));
        Book gof = new Book("222", "Design Patterns", "Gang of Four");
        gof.addItem(new BookItem("G1", "222"));
        library.addBook(clean);
        library.addBook(gof);

        // Members via the factory.
        Member alice = MemberFactory.create(MemberType.STUDENT, "S1", "Alice");
        Member bob = MemberFactory.create(MemberType.FACULTY, "F1", "Bob");
        library.registerMember(alice);
        library.registerMember(bob);

        // Search
        System.out.println("Search 'design':");
        List<Book> found = library.search("design");
        for (Book book : found) {
            System.out.printf("  %s by %s (%d/%d available)%n",
                    book.getTitle(), book.getAuthor(), book.availableCount(), book.totalCount());
        }

        // Borrowing
        System.out.println("\nBorrowing (day 0):");
        library.borrowBook("S1", "111", 0);   // Alice borrows Clean Code
        library.borrowBook("F1", "222", 0);    // Bob borrows the only GoF copy

        // Reserve a title that's now fully loaned
        System.out.println("\nAlice reserves Design Patterns (all copies out):");
        library.reserveBook("S1", "222", 1);

        // Bob returns overdue -> fine, and Alice is notified of her reservation
        System.out.println("\nBob returns Design Patterns late (day 35, due day 30):");
        library.returnBook("G1", 35);

        // Due-date reminders
        System.out.println("\nAt day 13:");
        library.sendDueReminders(13);   // Alice's Clean Code (due day 14) is close

        // Swap the fine strategy at runtime
        System.out.println("\nSwitching to a tiered fine policy, Alice returns late (day 20, due 14):");
        library.setFineStrategy(new TieredFineStrategy(1.0, 3.0, 3));
        library.returnBook("C1", 20);   // 6 days overdue: 3*1 + 3*3 = 12.00
    }
}
