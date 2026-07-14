package chapter30;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Coordinator: manages the catalog and members, and runs the borrow / return /
 * reserve workflows. Fine calculation is delegated to a pluggable strategy;
 * members are notified via the Notifiable (Observer) interface.
 */
public class Library {
    private final Map<String, Book> books = new HashMap<>();
    private final Map<String, Member> members = new HashMap<>();
    private final Map<String, Loan> activeLoans = new HashMap<>();          // barcode -> loan
    private final Map<String, List<Reservation>> reservations = new HashMap<>(); // isbn -> queue
    private FineStrategy fineStrategy;

    public Library(FineStrategy fineStrategy) {
        this.fineStrategy = fineStrategy;
    }

    public void setFineStrategy(FineStrategy fineStrategy) {
        this.fineStrategy = fineStrategy;
    }

    public void addBook(Book book) {
        books.put(book.getIsbn(), book);
    }

    public void registerMember(Member member) {
        members.put(member.getId(), member);
    }

    /** Search titles by a case-insensitive substring of title or author. */
    public List<Book> search(String query) {
        String q = query.toLowerCase();
        List<Book> results = new ArrayList<>();
        for (Book book : books.values()) {
            if (book.getTitle().toLowerCase().contains(q)
                    || book.getAuthor().toLowerCase().contains(q)) {
                results.add(book);
            }
        }
        return results;
    }

    public void borrowBook(String memberId, String isbn, int day) {
        Member member = members.get(memberId);
        Book book = books.get(isbn);
        if (member == null || book == null) {
            System.out.println("  Borrow failed: unknown member or book");
            return;
        }
        if (member.loanCount() >= member.maxBooks()) {
            System.out.printf("  %s has reached the borrow limit (%d)%n",
                    member.getName(), member.maxBooks());
            return;
        }
        BookItem item = book.findAvailableItem();
        if (item == null) {
            System.out.printf("  '%s' has no available copy — consider reserving%n", book.getTitle());
            return;
        }
        int dueDay = day + member.loanPeriodDays();
        item.setStatus(BookStatus.LOANED);
        item.setDueDay(dueDay);
        Loan loan = new Loan(member, item, day, dueDay);
        member.addLoan(loan);
        activeLoans.put(item.getBarcode(), loan);
        System.out.printf("  %s borrowed '%s' (copy %s), due day %d%n",
                member.getName(), book.getTitle(), item.getBarcode(), dueDay);
    }

    public void returnBook(String barcode, int day) {
        Loan loan = activeLoans.remove(barcode);
        if (loan == null) {
            System.out.println("  Return failed: no active loan for " + barcode);
            return;
        }
        BookItem item = loan.getItem();
        Book book = books.get(item.getIsbn());
        int overdueDays = Math.max(0, day - loan.getDueDay());
        loan.getMember().removeLoan(loan);
        item.setStatus(BookStatus.AVAILABLE);
        System.out.printf("  %s returned '%s' (copy %s)%n",
                loan.getMember().getName(), book.getTitle(), barcode);
        if (overdueDays > 0) {
            double fine = fineStrategy.calculateFine(overdueDays);
            System.out.printf("    Overdue %d day(s) -> fine $%.2f%n", overdueDays, fine);
        }
        handoffToReserver(book, item);
    }

    private void handoffToReserver(Book book, BookItem item) {
        List<Reservation> queue = reservations.get(book.getIsbn());
        if (queue != null && !queue.isEmpty()) {
            Reservation next = queue.remove(0);
            item.setStatus(BookStatus.RESERVED);
            next.getMember().onNotify("'" + book.getTitle() + "' is now available for pickup");
        }
    }

    public void reserveBook(String memberId, String isbn, int day) {
        Member member = members.get(memberId);
        Book book = books.get(isbn);
        if (member == null || book == null) {
            System.out.println("  Reserve failed: unknown member or book");
            return;
        }
        reservations.computeIfAbsent(isbn, k -> new ArrayList<>())
                .add(new Reservation(member, isbn, day));
        System.out.printf("  %s reserved '%s'%n", member.getName(), book.getTitle());
    }

    /** Observer push: remind members whose loans are due within 2 days. */
    public void sendDueReminders(int day) {
        System.out.println("  Sending due-date reminders:");
        for (Loan loan : activeLoans.values()) {
            int daysLeft = loan.getDueDay() - day;
            if (daysLeft <= 2) {
                Book book = books.get(loan.getItem().getIsbn());
                loan.getMember().onNotify(
                        "'" + book.getTitle() + "' is due in " + daysLeft + " day(s)");
            }
        }
    }
}
