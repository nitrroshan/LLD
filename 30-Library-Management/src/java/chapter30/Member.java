package chapter30;

import java.util.ArrayList;
import java.util.List;

/**
 * Abstract borrower. Subclasses define borrowing policy (limit + loan period).
 * Implements Notifiable so the library can push messages (Observer).
 */
public abstract class Member implements Notifiable {
    private final String id;
    private final String name;
    private final List<Loan> loans = new ArrayList<>();

    protected Member(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() { return id; }
    public String getName() { return name; }

    public abstract int maxBooks();
    public abstract int loanPeriodDays();

    public int loanCount() {
        return loans.size();
    }

    public void addLoan(Loan loan) {
        loans.add(loan);
    }

    public void removeLoan(Loan loan) {
        loans.remove(loan);
    }

    public List<Loan> getLoans() {
        return loans;
    }

    @Override
    public void onNotify(String message) {
        System.out.printf("    [Notify %s] %s%n", name, message);
    }
}
