package chapter30;

/**
 * An active borrowing: who has which copy, when it was issued, and when it's due.
 */
public class Loan {
    private final Member member;
    private final BookItem item;
    private final int issueDay;
    private final int dueDay;

    public Loan(Member member, BookItem item, int issueDay, int dueDay) {
        this.member = member;
        this.item = item;
        this.issueDay = issueDay;
        this.dueDay = dueDay;
    }

    public Member getMember() { return member; }
    public BookItem getItem() { return item; }
    public int getIssueDay() { return issueDay; }
    public int getDueDay() { return dueDay; }
}
